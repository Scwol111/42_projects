create database wordpress;
grant all privileges on wordpress.* TO 'admin'@'localhost' identified by 'admin';
grant all privileges on wordpress.* TO 'admin'@'%' identified by 'admin';
flush privileges;