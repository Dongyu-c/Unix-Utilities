#include<iostream>
#include<stdio.h>

#include<fcntl.h>
#include<stdlib.h>

#include<unistd.h>


int main(int argc, char * argv[])
{
	
	int fd;
	char buffer[4096];
	
	
	for (int i = 1; i < argc; i++) {
		
		fd = open(argv[i], O_RDONLY);
		
		if (fd < 0) {
			printf ( "wcat: cannot open file\n" );
			exit(1);
		}
		
		int  ret;
		while ((ret = read(fd, buffer, 4096)) > 0) {
			write(STDOUT_FILENO, buffer, ret);
		}
		close(fd);
	}
	exit(0);
}

