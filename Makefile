test:
	g++ -Wall -std=c++20 -I./src/ -I./testing/ testing/dedup-tests.cc src/dedup/*.cc -o test
	./test
