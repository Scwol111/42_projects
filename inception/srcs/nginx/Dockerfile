FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add --update nginx openssl openssh-server supervisor vim sudo
RUN mkdir -p /run/nginx

RUN rm /etc/supervisord.conf
RUN rm /etc/nginx/nginx.conf

COPY ./tools/nginx.conf /etc/nginx/
COPY ./tools/site/ /var/www/site/
COPY ./tools/supervisord.conf /etc/
COPY ./tools/start.sh /tmp/

EXPOSE 80 443 22

CMD ["/tmp/start.sh"]