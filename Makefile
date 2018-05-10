swapper:*.cpp
	g++ -std=c++14 -Wall -Werror *.cpp -o swapper

.PHONY: clean

clean:
	rm swapper
