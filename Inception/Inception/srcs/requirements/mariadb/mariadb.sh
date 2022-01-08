rc default

/etc/init.d/mariadb setup

rc-service mariadb start

mysql -u root --skip-password -e "CREATE DATABASE wordpress;"

mysql -u root --skip-password -e "CREATE USER '$ROOT_USER'@'%' IDENTIFIED BY '$ROOT_PASSWORD';"

mysql -u root --skip-password -e "GRANT ALL PRIVILEGES ON wordpress.* TO '$ROOT_USER'@'%';"

mysql -u root --skip-password -e "FLUSH PRIVILEGES;"

mysql -u root wordpress < wordpress.sql

mysql -u root -e "ALTER USER 'root'@'flouie.42.fr' IDENTIFIED BY '$ROOT_PASSWORD';"

rc-service mariadb stop

/usr/bin/mysqld_safe

