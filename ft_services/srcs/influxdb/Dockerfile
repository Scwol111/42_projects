# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 16:52:54 by tclaudin          #+#    #+#              #
#    Updated: 2020/12/23 15:33:50 by tclaudin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update supervisor wget rsync influxdb vim

RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
RUN apk add glibc-2.28-r0.apk

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.0_linux_amd64.tar.gz
RUN tar xf telegraf-1.17.0_linux_amd64.tar.gz
RUN cp -r /telegraf-1.17.0/* /
RUN ./usr/bin/telegraf -sample-config --input-filter docker --output-filter influxdb > /etc/telegraf/telegraf.conf 

RUN rm /etc/supervisord.conf
COPY ./data/supervisord.conf /etc/

COPY ./data/telegraf.conf /etc/telegraf/

VOLUME [ "/var/lib/influxdb" ]

EXPOSE 8086

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]