#include<iostream>
#include<string.h>
#include<stdio.h>

#include<fcntl.h>
#include<stdlib.h>

#include<sys/types.h>
#include<unistd.h>




void unfold(char * path) { 

	
	int fd = open(path, O_RDONLY);

	if (fd <0) {
		printf("wunzip: cannot open file\n"); 
		exit(1);
	}	

	char buffer;
	int count;


	while (true) {

		if (read(fd, &count, 4) != 4) {
			break;
		}
		read(fd,&buffer,1); 

		for (int i = 0; i < count; i++) {
			write(STDOUT_FILENO, &buffer, 1);
		}
	
	}
	close(fd);

}

int main(int argc, char** argv) {
	
	if (argc > 1) {
		for (int i = 1; i < argc; i++)
		{
			unfold(argv[i]);
		}
		exit(0);

	}
	
	printf("wunzip: file1 [file2 ...]\n");
	exit(1);
	

}