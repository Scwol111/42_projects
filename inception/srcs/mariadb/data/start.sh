#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

echo "INSTALL SERVER"
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

echo "CREATING USER"
/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_wordpress.sql

echo "SEND DATABASE"
rc-service mariadb start
mysql --user=$WP_DATABASE_USR --password=$WP_DATABASE_PWD $WP_DATABASE_NAME < /tmp/wordpress.sql
rc-service mariadb stop

echo "LAUNCH SERVER"
/usr/bin/mysqld --user=mysql --console
