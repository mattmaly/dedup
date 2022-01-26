test:
	g++ -Wall -std=c++20 -I./src/ testing/dedup-tests.cc -o test
	./test
