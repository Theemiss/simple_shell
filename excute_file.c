#include "shell.h"
/**
 * read_file - read command from a file
 * @filename:file name char
 * Return: -1 or  0
 */

int read_file(char **filename)
	{
		int fd, rd;
		char *buff = malloc(sizeof(char) * BUFSIZ);
		char **line;

		fd = open(filename[1], O_RDWR);
		if (fd == -1)
		{
			perror("hsh ");
			exit(-1);
		}

		rd = read(fd, buff, BUFSIZE);
		if (rd == -1)
		{
			return (0);
		}
			line = parse_cmd(buff);
			path_cmd(line);
			handle_builtin(line);
		exit(0);
	}
