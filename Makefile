test: build/dedup-tests-main.o build/test-cases/regular-file-test.o
	g++ -Wall -std=c++20 -I./src/ build/dedup-tests-main.o build/test-cases/*.o src/dedup/*.cc -o test
	./test

build/dedup-tests-main.o: testing/dedup-tests-main.cc
	mkdir -p build
	g++ -c -Wall -std=c++20 testing/dedup-tests-main.cc -o build/dedup-tests-main.o
build/test-cases/%.o: testing/test-cases/%.cc
	mkdir -p build/test-cases
	g++ -c -Wall -std=c++20 -I./src/ -I./testing/ testing/test-cases/*.cc -o $@
