#include "shell.h"
/**
 * exit_bul - exit shell
 *@cmd:command
 * Return:int
 */
int  exit_bul(char **cmd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(cmd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
			return (-1);
		}
	}
	statue = _atoi(cmd[1]);
	exit(statue);
}


/**
 * change_dir - change directory command
 * @cmd: command
 * Return: 1 in success
 */
int change_dir(char **cmd)
{
	int value = -1;
	char path[PATH_MAX];
	char cwd[PATH_MAX];

	if (cmd[1] == NULL || _strcmp(cmd[1], "~") == 0)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
		value = chdir(getenv("OLDPWD"));
	else if (_strcmp(cmd[1], "..") == 0)
		value = chdir(cmd[1]);
	else if (_strcmp(cmd[1], ".") == 0)
		value = chdir(cmd[1]);
	else if (cmd[1][0] != '/')
	{
		_strcpy(path, getenv("PWD"));
		_strcat(path, "/");
		_strcat(path, cmd[1]);
		value = chdir(path);
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
		return (-1);
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - display envirment variable bultin
 *@cmd:command
 * Return:int
 */
int dis_env(__attribute__((unused)) char **cmd)
{
size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * display_help - builtin to display help
 *
 * @cmd:command to excute
 * Return: int
 */
int display_help(char **cmd)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bul - echo bultin
 *
 * @cmd: commande line
 * Return: always 0
 */
int echo_bul(char **cmd)
{

	if (_strcmp(cmd[1], "$?") == 0)
	{
		system("exec echo $?");
	}
	else if (_strcmp(cmd[1], "$$") == 0)
	{
		system("exec echo $$");
	}
	else if (_strcmp(cmd[1], "$PATH") == 0)
	{
		system("exec echo $PATH");
	}
	else
		return (print_echo(cmd));

	return (0);
}
