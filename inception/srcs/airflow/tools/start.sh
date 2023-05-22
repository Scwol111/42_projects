#!/bin/sh

airflow users create \
	--password $AIRFLOW_PWD\
    --username $AIRFLOW_USER\
    --firstname Tofwin \
    --lastname Claudin \
    --role Admin \
    --email tclaudin@student.21-school.ru

/usr/bin/supervisord -c /etc/supervisord.conf