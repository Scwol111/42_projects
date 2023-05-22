#!/bin/bash

curl -sfL https://get.k3s.io \
      | \
        sh -s - \
          server \
          --write-kubeconfig-mode=644 \
          --flannel-iface=eth1

/usr/local/bin/kubectl apply -f /vagrant/app1.yaml
/usr/local/bin/kubectl apply -f /vagrant/app2.yaml
/usr/local/bin/kubectl apply -f /vagrant/app3.yaml
/usr/local/bin/kubectl apply -f /vagrant/ingress.yaml