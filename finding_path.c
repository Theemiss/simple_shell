#include "shell.h"

/**
 * path_cmd - function will search directories in $PATH environment variable
 *
 * @tokens: Parsed commands passed from input.
 *
 * Return: 1 on failure, or 0 on Success.
 */
int path_cmd(char **tokens)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build_cmd(*tokens, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*tokens = _strdup(cmd_path);
			free(path);
			return (-1);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}
	if (path != NULL)
		free(path);
	return (1);
}
/**
 * build_cmd - builds full command path from input.
 * @token: The command passed.
 * @value: The current directory found to have the command file.
 *
 * Return: Full command path.
 */
char *build_cmd(char *token, char *value)
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
 * _getenv - Gets the value of an environment variable.
 * @name: Environment variable.
 *
 * Return: The value of the environment variable if found, else NULL.
 */
char *_getenv(char *name)
{
	size_t namelen;
	size_t valuelen;
	char *value;
	int i, x, j;

	namelen = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], namelen) == 0)
		{
			valuelen = _strlen(environ[i]) - namelen;
			value = malloc(sizeof(char) * valuelen);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = namelen + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
