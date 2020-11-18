#include "shell.h"
/**
 * history - write stdin in a file and store it
 *
 * @cmd:input stdin
 * Return: write it in a file 0 Success -1 Fail
 */
int history(char *cmd)
{
	char *filename = "/home/themis/Holberton/simple_shell/.simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (cmd)
	{
		while (cmd[len])
			len++;
		w = write(fd, cmd, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
