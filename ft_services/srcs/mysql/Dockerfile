# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:52:56 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/22 19:57:33 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update wget mariadb mariadb-client vim openrc

RUN mkdir /run/nginx

COPY ./data/start.sh /tmp/
COPY ./data/*.sql /tmp/

RUN sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i "s|.*skip-networking.*|skip-networking=false|g" /etc/my.cnf.d/mariadb-server.cnf

VOLUME [ "/var/lib/mysql" ]

EXPOSE 3306

CMD [ "/tmp/start.sh" ]