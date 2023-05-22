FROM alpine:latest

RUN apk update && apk upgrade
RUN	apk add --no-cache mariadb mariadb-client
RUN apk add --no-cache openrc

COPY ./data/start.sh /tmp/
COPY ./data/*.sql /tmp/

COPY ./tools/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
RUN rm -rf /var/lib/mysql/*

RUN openrc default

RUN touch /run/openrc/softlevel

EXPOSE 3306

CMD [ "/tmp/start.sh"]
