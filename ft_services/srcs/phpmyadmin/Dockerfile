# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:52:59 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/20 16:08:41 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update wget supervisor nginx vim
RUN apk add php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
RUN apk add php7-cli php7-fpm php7-mbstring php7-session php7-zip

RUN mkdir /run/nginx
RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.4-all-languages phpmyadmin
RUN chmod -R 777 /phpmyadmin/

RUN rm /etc/nginx/conf.d/default.conf
RUN rm /etc/supervisord.conf

COPY ./data/nginx.conf /etc/nginx/conf.d/
COPY ./data/supervisord.conf /etc/
COPY ./data/config.inc.php /phpmyadmin/

EXPOSE 5000

CMD [ "/usr/bin/supervisord", "-c", "/etc/supervisord.conf" ]
