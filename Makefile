debug: build_debug
	./build/cli/cli

build_debug:
	rm -rf build
	mkdir build
	cd build; cmake .. -DCMAKE_BUILD_TYPE=Debug; make
