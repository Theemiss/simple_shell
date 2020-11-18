#include "shell.h"

/**
 * history_dis - display history
 * @cmd:command
 * Return: 0 Succes -1 Fail
 */
int history_dis(__attribute__((unused))char **cmd)
{
	{
	int fd, fw, rd = 1;
	char c;
	char *filename = "/home/themis/Holberton/simple_shell/.simple_shell_history";

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (-1);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			perror("Error");
			return (-1);
		}
	}
	_putchar('\n');
	return (1);
}
}
/**
 * print_echo - excute echo
 * @cmd:command
 * Return: 0 Succes -1 Fail
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
