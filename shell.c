#include "shell.h"

/**
 * main - simple shell
 * @argc:arg count
 * @argv:args input to shell
 * Return:int
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0;

	if (argv[1] != NULL)
		read_file(argv);
	signal(SIGINT, signal_to_handel);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		fflush(stdin);
		counter++;
		input = _getline();
		if (input == NULL)
			continue;
		else
			history(input);
		cmd = parse_cmd(input);
		if (cmd[0] == NULL)
		{
			free(cmd);
			continue;
		}
		if (check_builtin(cmd) == 0)
		{
			handle_builtin(cmd);
			free_all(cmd, input);
			continue;
		}
		else
		{
		path_cmd(cmd);
			if (check_cmd(cmd, counter) == -1)
			{
				free_all(cmd, input);
				break;
			}
				free((char *)cmd);
			}
			free(input);
	}
	return (0);
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"exit", NULL},
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * free_all - free pointer in main
 * @cmd:pointer to pointer char
 * @line:pointer
 * Return:void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
