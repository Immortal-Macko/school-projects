FROM alpine:3.12

RUN apk update  && apk add nginx openssl

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Moscow/L=Moscow/O=Ecole42/OU=School21/CN=flouie" -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt

COPY ./nginx.sh /
COPY ./nginx.conf ./etc/nginx/conf.d/default.conf
RUN mkdir run/nginx/

CMD sh nginx.sh

