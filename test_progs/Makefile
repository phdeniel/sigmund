all: allfs 

clean:
	rm -fr *.o 

test_pseudofs: createmanyexports.pl
	@cp createmanyexports.pl $$BUILD_TEST_DIR
	@echo "createmanyexports.pl copied to  $$BUILD_TEST_DIR"

allfs: test_pseudofs

xattr:
	@echo "Nothing to build for xattr"

pynfs40:
	@echo "Nothing to build for pynfs40"

pynfs41:
	@echo "Nothing to build for pynfs41"

