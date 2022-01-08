FROM alpine:3.12

RUN apk update && apk add php7 && apk add php7-fpm && apk add php7-mysqli 

RUN apk add php7 php7-fpm php7-mbstring php7-session php7-json php7-mysqli php7-gd php7-xml php7-curl php7-iconv

COPY start_wordpress.sh ./
COPY www.conf /etc/php7/php-fpm.d/

WORKDIR var/www/
RUN mkdir data
ADD https://wordpress.org/latest.tar.gz ./data/
RUN cd data && tar -xf latest.tar.gz && rm -rf latest.tar.gz
COPY wp-config.php ./data/wordpress/

WORKDIR /
CMD sh start_wordpress.sh && /usr/sbin/php-fpm7 -F
