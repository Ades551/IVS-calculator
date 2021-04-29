CC = g++
FILES = debug/ mockup/ plan/ profiling/ src/ .gitignore dokumentácia.pdf LICENSE README.md .git # files to pack in repo dir
NAME = xrajko00_xphanj00_xbuban00 # package name

.PHNONY: all install clean test pack doc getlibs run profile

all: profile
	./setup.sh && cd build && cmake .. && make

# create installer
install: all
	cd ./install/ && ./install.sh

clean:
	rm -rf build/ doxygen-gen/ profiling/profiling profiling/*.out

test:
	./build/math_test

pack: clean
	cd .. && mkdir -p $(NAME)/doc && mkdir -p $(NAME)/install && mkdir -p $(NAME)/repo
	cd ../$(NAME)/doc && doxygen ../../src/Doxyfile
	cd ../$(NAME) && cp ../src/install/*.deb ./install/
	cd .. && cp -r $(FILES) ./$(NAME)/repo
	cd .. && zip -r $(NAME) ./$(NAME)/
	rm -fr ../$(NAME)/

doc:
	doxygen Doxyfile

getlibs:
	sudo apt-get install qt5-default

run:
	./build/ivs-calc

profile:
	cd profiling && $(CC) -pg -g -o profiling *.cpp ../lib/*.cpp
