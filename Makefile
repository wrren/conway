all: cnwy

cnwy:
	pushd . && cd build && cmake .. && make && popd

test: bin/tests cnwy
	pushd . && cd build && cmake .. && make && popd && ./bin/tests

