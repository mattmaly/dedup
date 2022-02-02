#ifndef DEDUP_UTIL_POSSIBLE_ERROR
#define DEDUP_UTIL_POSSIBLE_ERROR

#include <string>
#include <utility>
#include <variant>

// PossibleError<T> is conceptually like a std::variant<T, std::string>, where
// the std::string variant case stores an error message in the case that the
// creation and/or initialization of the T variant case encountered some
// failure. It is most commonly used alongside a static factory class function,
// to support error-handling with object initialization.
template <typename T>
class PossibleError {
 public:
     // Creates and returns a PossibleError<T> (for which IsError() returns
     // true) containing the given error message.
     static PossibleError<T> MakeError(std::string error) {
          return PossibleError(
                    ErrorStringWrapper { .value = std::move(error) });
     }

     // Constructs a PossibleError<T> containing the given value.
     PossibleError(T&& value) : value_or_error_(std::in_place_index<0>,
                                                std::forward<T>(value)) {}

     // Returns whether this PossibleError<T> contains an error (if not, then
     // it contains some value of type T).
     bool IsError() const {
          return value_or_error_.index() == 1;
     }

     // Returns this PossibleError<T>'s value of type T. If IsError() is true,
     // then this function will throw a std::bad_variant_access exception.
     const T& value() const & {
          return std::get<0>(value_or_error_);
     }

     // Same as above, but returns an rvalue in the case that this
     // PossibleError<T> is also an rvalue.
     T&& value() && {
          return std::get<0>(std::move(value_or_error_));
     }

     // Returns this PossibleError<T>'s error string. If IsError() is false,
     // then this function will throw a std::bad_variant_access exception.
     const std::string& error() const {
          return std::get<1>(value_or_error_);
     }

 private:
     struct ErrorStringWrapper {
          std::string value;
     };
     // Constructs a PossibleError<T> containing the given error message. This
     // constructor is private (and uses an internal wrapper type) to avoid
     // ambiguity when T is implicitly convertible to or from std::string.
     // Callers are instead forced to use the MakeError() static factory
     // function to create errors.
     explicit PossibleError(ErrorStringWrapper error)
               : value_or_error_(std::in_place_index<1>,
                                 std::move(error.value)) {}
     std::variant<T, std::string> value_or_error_;
};

#endif  // DEDUP_UTIL_POSSIBLE_ERROR
