dist:
	tar --transform 's,^,sigmund-1.0/,' -cz --exclude="*.tar.gz" -f sigmund.tar.gz * 

rpm: dist
	rpmbuild -ta sigmund.tar.gz

cleandist:
	rm sigmund.tar.gz

