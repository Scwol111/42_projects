#!/bin/bash

minikube start #--vm-driver=virtualbox

#enable metallb
minikube addons enable metallb
minikube addons enable dashboard

#activate docker in minikube
eval $(minikube docker-env)

# apply metallb
kubectl apply -f ./srcs/metallb/metallb.yaml

# start nginx
docker build -t nginx_image ./srcs/nginx && kubectl apply -f ./srcs/nginx/nginx.yaml

# start mysql
kubectl apply -f ./srcs/mysql/pv_mysql.yaml && docker build -t mysql_image ./srcs/mysql && kubectl apply -f ./srcs/mysql/mysql.yaml

# start wordpress
docker build -t wordpress_image ./srcs/wordpress && kubectl apply -f ./srcs/wordpress/wordpress.yaml

# start phpmyadmin
docker build -t phpmyadmin_image ./srcs/phpmyadmin && kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml

# start ftps
docker build -t ftps_image ./srcs/ftps && kubectl apply -f ./srcs/ftps/ftps.yaml

# start influxdb
kubectl apply -f ./srcs/influxdb/pv_influx.yaml && docker build -t influx_image ./srcs/influxdb && kubectl apply -f ./srcs/influxdb/influx.yaml

# start grafana
docker build -t grafana_image ./srcs/grafana && kubectl apply -f ./srcs/grafana/grafana.yaml

#open dashboard
minikube dashboard