#include<iostream>
#include<string.h>
#include<stdio.h>

#include<fcntl.h>
#include<stdlib.h>

#include<sys/types.h>
#include<unistd.h>





int main(int argc, char* argv[]) {

	if (argc > 1) {
		char pre;
		char cur;
		int count = 0;

		for (int i = 1; i < argc; i++) {
			int fd = open(argv[i], O_RDONLY);

			if (fd < 0) {
				printf("wzip: cannot open file\n");
				exit(1);
			}


			if (read(fd, &cur, 1) == 0) {
				continue;
			}

			
			if (count == 0) {
				pre = cur;
			}

			if (cur != pre) {
				if (count > 0) {
					write(STDOUT_FILENO, &count, 4);
					write(STDOUT_FILENO, &pre, 1);
				}
				count = 0;
			}

			pre = cur;
			count ++;


			while (read(fd, &cur, 1) > 0) {

				if (cur != pre) {
					if (count > 0) {
						write(STDOUT_FILENO, &count, 4);
						write(STDOUT_FILENO, &pre, 1);
					}
					count = 0;
				}

				count ++;
				pre = cur;
			}
			
			close(fd);

			}

		if (count > 0) {
			write(STDOUT_FILENO, &count, 4);
			write(STDOUT_FILENO, &pre, 1);
		}

		
	
	exit(0);
	}
	printf("wzip: file1 [file2 ...]\n");
	exit(1);

}