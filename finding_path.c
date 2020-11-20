#include "shell.h"

/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value)
{
	char *cmd_path;
	size_t cmd_len;

	cmd_len = _strlen(value) + _strlen(token) + 2;
	cmd_path = malloc(sizeof(char) * cmd_len);
	if (!cmd_path)
	{
		return (NULL);
	}

	memset(cmd_path, 0, cmd_len);

	cmd_path = _strcat(cmd_path, value);
	cmd_path = _strcat(cmd_path, "/");
	cmd_path = _strcat(cmd_path, token);

	return (cmd_path);
}
/**
 * _getenv - Gets The Value Of Enviroment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *_getenv(char *name)
{
	size_t namel;
	size_t valuel;
	char *value;
	int i, x, j;

	namel = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], namel) == 0)
		{
			valuel = _strlen(environ[i]) - namel;
			value = malloc(sizeof(char) * valuel);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = namel + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
