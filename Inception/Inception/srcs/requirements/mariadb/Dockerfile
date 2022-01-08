FROM alpine:3.12
VOLUME ["/sys/fs/cgroup"]
RUN apk update 

RUN apk add openrc mysql mysql-client
COPY mariadb.sh /
COPY wordpress.sql /
COPY my.cnf /etc/
RUN chmod +x mariadb.sh

CMD sh mariadb.sh

