#include<iostream>
#include<string.h>
#include<stdio.h>

#include<fcntl.h>
#include<stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main(int argc, char* argv[]) {
	
	if (argc <= 1) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}

	int fd;
	if (argc == 2) {
		fd = STDIN_FILENO;
	}else{
		fd = open(argv[2], O_RDONLY);
		if (fd < 0) {
			printf("wgrep: cannot open file\n");
			exit(1);
		}
	}
	
	char* searchResult = argv[1];

	char buffer;
	std::string content = "";
	
	while (read(fd, &buffer, 1) > 0) {

		content.push_back(buffer);
		if (buffer == '\n') {
			if (content.find(searchResult,0) != std::string::npos) {
				write(STDOUT_FILENO, content.c_str(), content.size());
			}
			content = "";
		}
	}
	close(fd);
	exit(0);
}







