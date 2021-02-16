# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:52:50 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/23 14:54:53 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add vsftpd openssl vim

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/ftps.key -out /etc/ssl/certs/ftps.crt -subj "/C=RU/ST=Tatarstan/L=Kazan/O=tclaudin/OU=IT/CN=tclaudin" 

RUN echo "root:root" | chpasswd
RUN rm /etc/vsftpd/vsftpd.conf
COPY ./data/vsftpd.conf /etc/vsftpd/

COPY ./data/start.sh /tmp/

EXPOSE 21

CMD ["/tmp/start.sh"]