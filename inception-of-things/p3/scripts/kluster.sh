#!/bin/bash

# create kluster
k3d cluster create -p 8080:80@loadbalancer -p 8888:8888@loadbalancer
sleep 5

# create namespaces
kubectl create namespace argocd
kubectl create namespace dev
sleep 3

# install argocd
kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
kubectl patch svc argocd-server -n argocd -p '{"spec": {"type": "LoadBalancer"}}'

# create argocd project
kubectl apply -f ../confs/project.yaml -n argocd
sleep 25

# create ingress for argocd
kubectl apply -f ../confs/argo-ingress.yaml -n argocd
sleep 15

# get password to argocd
kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d > argo_password.txt
# kubectl -n dev port-forward deployment/wil-playground 8888:8888
