#!/bin/sh

adduser -D tclaudin
echo "$SSH_USER:$SSH_PWD" | chpasswd

/usr/bin/ssh-keygen -A

mkdir /etc/nginx/ssl

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/C=RU/ST=Tatarstan/L=Kazan/O=tclaudin/OU=IT/CN=tclaudin" 

/usr/bin/supervisord -c /etc/supervisord.conf