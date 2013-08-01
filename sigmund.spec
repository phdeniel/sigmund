# No debuginfo:
%define debug_package %{nil}

Name: sigmund
Version: 1
Release: 1%{?dist}
Summary: Sigmund Test Suite
License: LGPLv3
Group: Applications/System
BuildArch: noarch
Requires:  filesystem, bash, grep
Url: http://github.com/phdeniel/sigmund/
Source0: sigmund.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Prefix: /opt

%description
Sigmund test suite.
This is a non-regression suite dedicated to filesystems.

%prep
%setup -q -n %{name}-%{version}

%build
# Nothing to do, those are scripts

%install
install -d %{buildroot}/opt/sigmund
install -d %{buildroot}%{_sysconfdir}

tar cf - . | (cd %{buildroot}/opt/sigmund; tar xfp -)
mv %{buildroot}/opt/sigmund/sigmund.d %{buildroot}%{_sysconfdir}/sigmund.d/

rm %{buildroot}/opt/sigmund/sigmund.spec
rm %{buildroot}/opt/sigmund/do_rpm.sh
rm %{buildroot}/opt/sigmund/README
rm %{buildroot}/opt/sigmund/Sigmund_HowTO.pdf
rm -fr %{buildroot}/opt/sigmund/wiki 
rm -fr %{buildroot}/opt/sigmund/sides 


%files
%defattr(-,root,root)
/opt/sigmund/behavior/*
/opt/sigmund/test_progs/*
/opt/sigmund/modules/*
/opt/sigmund/sigmund.sh
/opt/sigmund/build_test.sh
/opt/sigmund/test_framework.inc
%dir %{_sysconfdir}/sigmund.d/
%config(noreplace) %{_sysconfdir}/sigmund.d/*

%post

%clean
[ $RPM_BUILD_ROOT != "/" ] && rm -fr $RPM_BUILD_ROOT

