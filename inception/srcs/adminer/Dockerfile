FROM alpine:latest

RUN apk update && apk upgrade

RUN apk add ca-certificates curl tar xz openssl
RUN adduser -u 82 -D -S -G www-data www-data

ENV PHP_INI_DIR=/usr/local/etc/php

RUN set -eux; mkdir -p "$PHP_INI_DIR/conf.d"; [ ! -d /var/www/html ]; mkdir -p /var/www/html; chown www-data:www-data /var/www/html; chmod 777 /var/www/html

RUN apk add --update php7-cli php7-fpm php7-mbstring php7-session php7-zip php7-json
RUN apk add --upgrade php7-imagick php7-xmlrpc php-mysqli unzip php-gettext php7\
		php7-fpm php7-bcmath php7-bz2 php7-calendar	php7-ctype php7-curl php7-dom php7-exif			\
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
		php7-zlib wget curl

RUN	echo "upload_max_filesize = 128M" >> /usr/local/etc/php/conf.d/0-upload_large_dumps.ini \
&&	echo "post_max_size = 128M" >> /usr/local/etc/php/conf.d/0-upload_large_dumps.ini \
&&	echo "memory_limit = 1G" >> /usr/local/etc/php/conf.d/0-upload_large_dumps.ini \
&&	echo "max_execution_time = 600" >> /usr/local/etc/php/conf.d/0-upload_large_dumps.ini \
&&	echo "max_input_vars = 5000" >> /usr/local/etc/php/conf.d/0-upload_large_dumps.ini

STOPSIGNAL SIGINT

RUN	addgroup -S adminer \
&&	adduser -S -G adminer adminer \
&&	mkdir -p /var/www/html \
&&	mkdir -p /var/www/html/plugins-enabled \
&&	chown -R adminer:adminer /var/www/html

WORKDIR /var/www/html

RUN	set -x 
RUN	apk add --no-cache --virtual .build-deps \
	postgresql-dev \
	sqlite-dev \
	unixodbc-dev \
	freetds-dev

RUN apk add libxml2-dev

ENV PHPIZE_DEPS \
		autoconf \
		dpkg-dev dpkg \
		file \
		g++ \
		gcc \
		libc-dev \
		make \
		pkgconf \
		re2c

RUN apk add --no-cache \
		ca-certificates \
		curl \
		tar \
		xz \
		openssl


ENV PHP_INI_DIR /usr/local/etc/php
RUN set -eux; \
	mkdir -p "$PHP_INI_DIR/conf.d"; \
	chown www-data:www-data /var/www/html

ENV PHP_CFLAGS="-fstack-protector-strong -fpic -fpie -O2 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64"
ENV PHP_CPPFLAGS="$PHP_CFLAGS"
ENV PHP_LDFLAGS="-Wl,-O1 -pie"

ENV GPG_KEYS 42670A7FE4D0441C8E4632349E4FDC074A4EF02D 5A52880781F755608BF815FC910DEB46F53EA312

ENV PHP_VERSION 7.4.27
ENV PHP_URL="https://www.php.net/distributions/php-7.4.27.tar.xz" PHP_ASC_URL="https://www.php.net/distributions/php-7.4.27.tar.xz.asc"
ENV PHP_SHA256="3f8b937310f155822752229c2c2feb8cc2621e25a728e7b94d0d74c128c43d0c"

RUN set -eux; \
	apk add --no-cache --virtual .fetch-deps gnupg; \
	mkdir -p /usr/src; \
	cd /usr/src; \
	curl -fsSL -o php.tar.xz "$PHP_URL"; \
	if [ -n "$PHP_SHA256" ]; then \
		echo "$PHP_SHA256 *php.tar.xz" | sha256sum -c -; \
	fi; \
	if [ -n "$PHP_ASC_URL" ]; then \
		curl -fsSL -o php.tar.xz.asc "$PHP_ASC_URL"; \
		export GNUPGHOME="$(mktemp -d)"; \
		for key in $GPG_KEYS; do \
			gpg --batch --keyserver keyserver.ubuntu.com --recv-keys "$key"; \
		done; \
		gpg --batch --verify php.tar.xz.asc php.tar.xz; \
		gpgconf --kill all; \
		rm -rf "$GNUPGHOME"; \
	fi; \
	apk del --no-network .fetch-deps

COPY ./tools/docker-php-source /usr/local/bin/

RUN set -eux; \
	apk add --no-cache --virtual .build-deps \
		$PHPIZE_DEPS \
		argon2-dev \
		coreutils \
		curl-dev \
		libsodium-dev \
		libxml2-dev \
		linux-headers \
		oniguruma-dev \
		openssl-dev \
		readline-dev \
		sqlite-dev \
	; \
	export \
		CFLAGS="$PHP_CFLAGS" \
		CPPFLAGS="$PHP_CPPFLAGS" \
		LDFLAGS="$PHP_LDFLAGS" \
	; \
	docker-php-source extract; \
	cd /usr/src/php; \
	gnuArch="$(dpkg-architecture --query DEB_BUILD_GNU_TYPE)"; \
	./configure \
		--build="$gnuArch" \
		--with-config-file-path="$PHP_INI_DIR" \
		--with-config-file-scan-dir="$PHP_INI_DIR/conf.d" \
		--enable-option-checking=fatal \
		--with-mhash \
		--with-pic \
		--enable-ftp \
		--enable-mbstring \
		--enable-mysqlnd \
		--with-password-argon2 \
		--with-sodium=shared \
		--with-pdo-sqlite=/usr \
		--with-sqlite3=/usr \
		--with-curl \
		--with-openssl \
		--with-readline \
		--with-zlib \
		--with-pear \
		$(test "$gnuArch" = 's390x-linux-musl' && echo '--without-pcre-jit') \
	; \
	make -j "$(nproc)"; \
	find -type f -name '*.a' -delete; \
	make install; \
	find \
		/usr/local \
		-type f \
		-perm '/0111' \
		-exec sh -euxc ' \
			strip --strip-all "$@" || : \
		' -- '{}' + \
	; \
	make clean; \
	cp -v php.ini-* "$PHP_INI_DIR/"; \
	cd /; \
	docker-php-source delete; \
	runDeps="$( \
		scanelf --needed --nobanner --format '%n#p' --recursive /usr/local \
			| tr ',' '\n' \
			| sort -u \
			| awk 'system("[ -e /usr/local/lib/" $1 " ]") == 0 { next } { print "so:" $1 }' \
	)"; \
	apk add --no-cache $runDeps; \
	apk del --no-network .build-deps; \
	pecl update-channels; \
	rm -rf /tmp/pear ~/.pearrc; php --version

COPY ./tools/docker-php-ext-* ./tools/docker-php-entrypoint /usr/local/bin/
RUN docker-php-ext-enable sodium

RUN apk add php7-pdo_odbc

RUN	docker-php-ext-install pdo_mysql
RUN	runDeps="$( \
		scanelf --needed --nobanner --format '%n#p' --recursive /usr/local/lib/php/extensions \
			| tr ',' '\n' \
			| sort -u \
			| awk 'system("[ -e /usr/local/lib/" $1 " ]") == 0 { next } { print "so:" $1 }' \
	)"
RUN	apk add --virtual .phpexts-rundeps $runDeps

COPY	./tools/*.php /var/www/html/

ENV	ADMINER_VERSION 4.8.1
ENV	ADMINER_DOWNLOAD_SHA256 2fd7e6d8f987b243ab1839249551f62adce19704c47d3d0c8dd9e57ea5b9c6b3
ENV	ADMINER_SRC_DOWNLOAD_SHA256 ef832414296d11eed33e9d85fff3fb316c63f13f05fceb4a961cbe4cb2ae8712

RUN	set -x \
&&	curl -fsSL https://github.com/vrana/adminer/releases/download/v$ADMINER_VERSION/adminer-$ADMINER_VERSION.php -o adminer.php \
&&	echo "$ADMINER_DOWNLOAD_SHA256  adminer.php" |sha256sum -c - \
&&	curl -fsSL https://github.com/vrana/adminer/archive/v$ADMINER_VERSION.tar.gz -o source.tar.gz \
&&	echo "$ADMINER_SRC_DOWNLOAD_SHA256  source.tar.gz" |sha256sum -c - \
&&	tar xzf source.tar.gz --strip-components=1 "adminer-$ADMINER_VERSION/designs/" "adminer-$ADMINER_VERSION/plugins/" \
&&	rm source.tar.gz

COPY	./tools/entrypoint.sh /usr/local/bin/
RUN chmod 777 /usr/local/bin/entrypoint.sh
ENTRYPOINT	[ "entrypoint.sh", "docker-php-entrypoint" ]

USER	adminer
CMD	[ "php", "-S", "[::]:5050", "-t", "/var/www/html" ]

EXPOSE 8080