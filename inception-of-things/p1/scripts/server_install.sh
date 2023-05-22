#!/bin/bash

sudo systemctl disable --now firewalld

curl -sfL https://get.k3s.io \
      | \
        sh -s - \
          server \
          --write-kubeconfig-mode=644 \
          --flannel-iface=eth1

cat /var/lib/rancher/k3s/server/node-token > /vagrant/node-token
