NAME = inception

all: linux reload

linux:
	echo "127.0.0.1 tclaudin.42.fr" >> /etc/hosts
	
stop:
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker volume rm $(docker volume ls -q)

prune: clean
	docker system prune -f

reload: 
	docker-compose -f srcs/docker-compose.yml up --build

.PHONY: linux stop clean prune reload all