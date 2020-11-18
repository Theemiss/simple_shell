#include "shell.h"
/**
 * check_cmd - check for command and excute
 * @cmd:command to check and excute
 *@counter: nuber of exctution of shell
 *Return: 1 success -1 if failed
 */
int check_cmd(char **cmd, int counter)
{
	pid_t pid;
	int status;

	if (cmd == NULL)
	{
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			print_error(cmd[0], counter);
			return (-1);
		}
		return (0);
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
/**
 * signal_to_handel - handle ^C
 *
 * @sig: int
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
/**
 * handle_builtin - excute builtin if found or excute commandes
 * @cmd: command to check
 * Return: int
 */

int handle_builtin(char **cmd)
{
	 bul_t bil[] = {
		{"exit", exit_bul},
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strncmp(cmd[0], (bil + i)->command, _strlen(cmd[0])) == 0)
		{
			return ((bil + i)->fun(cmd));
		}
		i++;
	}
	return (-1);
}
