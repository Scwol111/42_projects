FROM alpine:latest

RUN apk update && apk upgrade 
RUN apk add python3 supervisor vim
RUN apk add --update py-pip
RUN apk add --no-cache libressl-dev musl-dev libffi-dev 
RUN apk add gcc python3-dev openssl-dev

RUN rm /etc/supervisord.conf
COPY ./tools/supervisord.conf /etc/

RUN pip install --upgrade pip
RUN pip install cryptography
RUN pip install apache-airflow
RUN airflow db init

COPY ./tools/start.sh /tmp

EXPOSE 8080

CMD ["/tmp/start.sh"]
