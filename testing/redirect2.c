#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	printf("STDIN_FILENO: %d\n", STDIN_FILENO);
	int saved_stdin = dup(STDIN_FILENO);
	// < redirect
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1) 
	{
		perror("open");
		return (1);
	}

	dup2(fd, STDIN_FILENO);
	close(fd);

	static char buf[100];
	read(0, buf, 5);
	// This will restore it
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	printf("STDIN Restored!\n");
	printf("We read: %s\n", buf);


	return (0);
}

