#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>


int main()
{
	int fd, rw_fd;
	int ret;
	char buf[] = "hello lvjiayao\n";
	struct sockaddr_in server_addr;
	fd = socket(PF_INET, SOCK_STREAM, 0);
	if (fd<0)
	{
		printf("created socket error\n");
		return -1;
	}
	printf("fd=%d\n", fd);
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(8888);
	server_addr.sin_addr.s_addr = inet_addr("192.168.1.34");
	connect(fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
	write(fd, buf, sizeof(buf));
	return 0;
}