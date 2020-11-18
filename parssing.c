#include "shell.h"

/**
 * parse_cmd - parse the line of input
 * @input:line of input to parse
 * Return: double pointer to array
 */
char **parse_cmd(char *input)
{
char **tokens;
	char *token;
	int i, len;

	len = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ' || input[i] == '\n')
			len++;
	}
	len++;

	tokens = malloc(sizeof(char *) * len);
	if (!tokens)
	{
		return (NULL);
	}

	token = strtok(input, DELIM);
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}
