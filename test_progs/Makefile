all: allfs pynfs

clean:
	rm -fr *.o 
	rm -f test_mmap

test_mmap: test_mmap.c
	cc -o test_mmap test_mmap.c
	mv test_mmap $$BUILD_TEST_DIR

allfs: test_mmap



