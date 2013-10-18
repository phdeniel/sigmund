all: allfs 

clean:
	rm -fr *.o 
	rm -f test_mmap_read test_mmap_write

test_mmap_read: test_mmap_read.c
	@cc -o test_mmap_read test_mmap_read.c
	@rm -f $$BUILD_TEST_DIR/test_mmap_read
	@mv test_mmap_read $$BUILD_TEST_DIR
	@echo "test_mmap_read compiled and moved to  $$BUILD_TEST_DIR"

test_mmap_write: test_mmap_write.c
	@cc -o test_mmap_write test_mmap_write.c
	@rm  -f $$BUILD_TEST_DIR/test_mmap_write
	@mv test_mmap_write $$BUILD_TEST_DIR
	@echo "test_mmap_write compiled and moved to  $$BUILD_TEST_DIR"

test_pseudofs: createmanyexports.pl
	@cp createmanyexports.pl $$BUILD_TEST_DIR
	@echo "createmanyexports.pl copied to  $$BUILD_TEST_DIR"

allfs: test_mmap_read test_mmap_write test_pseudofs

xattr:
	@echo "Nothing to build for xattr"

pynfs40:
	@echo "Nothing to build for pynfs40"

pynfs41:
	@echo "Nothing to build for pynfs41"

