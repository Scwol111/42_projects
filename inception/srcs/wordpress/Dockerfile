FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update wget vim
RUN apk add --update php7-cli php7-fpm php7-mbstring php7-session php7-zip php7-json
RUN apk add --upgrade php7-imagick php7-xmlrpc php-mysqli unzip php-gettext php7\
		php7-fpm php7-bcmath php7-bz2 php7-calendar		\
		php7-ctype			\
		php7-curl			\
		php7-dom			\
		php7-exif			\
		php7-fileinfo		\
		php7-gd				\
		php7-gmp			\
		php7-iconv			\
		php7-imap			\
		php7-intl			\
		php7-json			\
		php7-mbstring		\
		php7-mcrypt			\
		php7-memcache		\
		php7-mysqli			\
		php7-mysqlnd		\
		php7-openssl		\
		php7-pcntl			\
		php7-pdo			\
		php7-pdo_mysql		\
		php7-pdo_pgsql		\
		php7-pdo_sqlite 	\
		php7-pgsql			\
		php7-phar			\
		php7-posix			\
		php7-session		\
		php7-shmop			\
		php7-simplexml		\
		php7-soap			\
		php7-sockets		\
		php7-sodium			\
		php7-sqlite3		\
		php7-sysvsem		\
		php7-sysvshm		\
		php7-tokenizer		\
		php7-xml			\
		php7-xmlreader		\
		php7-xmlwriter		\
		php7-xsl			\
		php7-zip			\
		php7-zlib

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz

COPY ./tools/wp-config.php /wordpress

RUN mkdir -p /var/www/ /var/www/
RUN mv /wordpress /var/www/

COPY ./conf/www.conf /etc/php7/php-fpm.d/
COPY ./conf/php-fpm.conf /etc/php7/php-fpm.conf

RUN	adduser -S nginx &&	addgroup -S nginx

COPY ./tools/start.sh /

EXPOSE 9000

CMD ["sh", "/start.sh"]