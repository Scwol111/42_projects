# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:53:01 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/23 15:17:36 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update wget vim nginx supervisor
RUN apk add --update php7-cli php7-fpm php7-mbstring php7-session php7-zip php7-json
RUN apk add --upgrade php7-imagick php7-xmlrpc php-mysqli unzip php-gettext
RUN mkdir /run/nginx

RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
COPY ./data/wp-config.php /wordpress/

RUN rm /etc/nginx/conf.d/default.conf
RUN rm /etc/supervisord.conf

COPY ./data/nginx.conf /etc/nginx/conf.d/
COPY ./data/supervisord.conf /etc/

EXPOSE 5050

CMD [ "/usr/bin/supervisord", "-c", "/etc/supervisord.conf" ]