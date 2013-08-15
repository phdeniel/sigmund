#!/usr/bin/perl

$CONFIG_DIR = "../ganesha_configs";

sub setup_server() {
    my ($MOUNTDIR, $PREFIX, $VERSION, $NUMBER, $FSAL) = @_;

    # create export config
    `${CONFIG_DIR}/createmanyexports.pl ${MOUNTDIR} ${PREFIX} ${VERSION} ${NUMBER} ${FSAL} > /tmp/exports.conf`;

    # move export config to server and restart server

}

sub setup_client() {
    # nothing to do.
}

setup_client();
setup_server();
