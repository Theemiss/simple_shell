#include "shell.h"
/**
 * exit_bul - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @env: Environment Variables
 * Return: Void (Exit Statue)
 */
void  exit_bul(char **cmd, char *input, char **env)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		free_env(env);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(input);
	free(cmd);
	free_env(env);
	exit(statue);
}


/**
 * change_dir - Change Dirctorie
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1, st = -1;
	char path[PATH_MAX];
	char cwd[PATH_MAX];
	char *c;

	if (cmd[1] == NULL || _strcmp(cmd[1], "~") == 0)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		chdir(getenv("OLDPWD"));
		value = 0;
	}
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
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
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
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int display_help(char **cmd, __attribute__((unused))int er)
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
 * echo_bul - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strcmp(cmd[1], "$?") == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strcmp(cmd[1], "$$") == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strcmp(cmd[1], "$PATH") == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
