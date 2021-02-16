# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:52:57 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/23 15:18:49 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update nginx openssl openssh-server supervisor vim sudo
RUN mkdir /run/nginx

RUN rm /etc/supervisord.conf
RUN rm /etc/nginx/conf.d/default.conf

COPY ./data/nginx.conf /etc/nginx/conf.d/
COPY ./data/site/ /var/www/site/
COPY ./data/supervisord.conf /etc/

RUN adduser -D tclaudin
RUN echo "tclaudin:tclaudin" | chpasswd

RUN /usr/bin/ssh-keygen -A

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=RU/ST=Tatarstan/L=Kazan/O=tclaudin/OU=IT/CN=tclaudin" 

EXPOSE 80 443 22

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]