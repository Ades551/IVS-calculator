FILES = plan/ profiling/ src/ .gitignore dokumentácia.pdf LICENSE README.md .git # files to pack in repo dir
NAME = xrajko00 # package name

all:
	./setup.sh && cd build && cmake .. && make

clean:
	rm -r build/

test:
	./build/math_test

pack:
	cd .. && mkdir -p ivs-calc/doc && mkdir -p ivs-calc/install && mkdir -p ivs-calc/repo
	cd ../ivs-calc/doc && doxygen ../../src/Doxyfile
	cd ../ivs-calc && cp ../src/install/*.deb ./install/
	cd .. && cp -r $(FILES) ./ivs-calc/repo
	cd .. && zip -r $(NAME) ./ivs-calc/
	rm -fr ../ivs-calc/

doc:
	doxygen Doxyfile

getlibs:
	sudo apt-get install qt5-default

run:
	./build/ivs-calc
