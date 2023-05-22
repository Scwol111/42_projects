FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add vsftpd openssl vim

RUN rm /etc/vsftpd/vsftpd.conf
COPY ./data/vsftpd.conf /etc/vsftpd/

COPY ./data/start.sh /tmp/

EXPOSE 21

CMD ["/tmp/start.sh"]