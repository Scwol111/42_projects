#!/bin/sh

echo "$FTPS_USER:$FTPS_PWD" | chpasswd

/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf