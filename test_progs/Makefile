all: allfs 

clean:
	rm -fr *.o 
	rm -f test_mmap_read test_mmap_write

test_mmap_read: test_mmap_read.c
	cc -o test_mmap_read test_mmap_read.c
	mv test_mmap_read $$BUILD_TEST_DIR

test_mmap_write: test_mmap_write.c
	cc -o test_mmap_write test_mmap_write.c
	mv test_mmap_write $$BUILD_TEST_DIR

allfs: test_mmap_read test_mmap_write



