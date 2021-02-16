<?php
  $cfg['PmaAbsoluteUri'] = 'http://192.168.99.101:5000/';
  $cfg['blowfish_secret']= '1234567890';
  $i = 0;
  $i++;
  $cfg['Servers'][$i]['host'] = 'mysql:3306';
  $cfg['Servers'][$i]['extension'] = 'mysqli';
  $cfg['Servers'][$i]['connect_type'] = 'tcp';
  $cfg['Servers'][$i]['compress'] = false;
  $cfg['Servers'][$i]['user'] = 'admin';
  $cfg['Servers'][$i]['password'] = 'admin';
?>