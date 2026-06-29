#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	printf("STDOUT_FILENO: %d\n", STDOUT_FILENO);
	int saved_stdout = dup(STDOUT_FILENO);
	// > redirect
	// int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// >> redirect
	int fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (fd == -1) 
	{
		perror("open");
		return (1);
	}

	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("Hello World!\n");
	// This will not work - STDOUT_FILENO (1) point to a file now!
	dup2(STDOUT_FILENO, STDOUT_FILENO);
	printf("STDOUT NOT Restored!\n");
	// This will restore it
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	printf("STDOUT Restored!\n");


	return (0);
}

