#include "shell.h"
/**
 * read_file - Read Command From File
 * @filename:Filename
 * Return: -1 or  0
 */

void read_file(char *filename)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	char *envi[50];
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	creat_envi(envi);
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, envi, counter, fp);

	}
	if (line)
		free(line);
	free_env(envi);
	fclose(fp);
	exit(0);
}
/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @envi: Enviroment Variable
 * @counter:Error Counter
 * @fp:File Descriptor
 * Return : Excute A line void
 */
void treat_file(char *line, char **envi, int counter, FILE *fp)
{
	char **cmd;

	cmd = parse_cmd(line);

		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul_for_file(cmd, line, envi, fp);
		}
		else if ((check_builtin(cmd)) == 0)
		{
			handle_builtin(cmd);
				free(cmd);
		}
		else
		{
			 check_cmd(cmd, line, envi, counter);
				free(cmd);
		}
}
/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @envi: Enviroment Variable
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_bul_for_file(char **cmd, char *line, char **envi, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		free_env(envi);
		fclose(fd);
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
	free(line);
	free(cmd);
	free_env(envi);
	fclose(fd);
	exit(statue);



}
