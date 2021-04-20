all:
	./setup.sh && cd build && cmake .. && make

clean:
	rm -r build/

test:
	./build/math_test

getlibs:
	sudo apt-get install qt5-default

run:
	./build/calc
