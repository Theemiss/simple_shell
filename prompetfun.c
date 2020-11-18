#include "shell.h"

/**
 * prompt - display prompt
 */
void prompt(void)
{
	_putchar('$');
	_putchar(' ');
}
/**
 * print_error - print error
 *
 * @cmd:command to return in failure
 * @counter:hsh counter
 * Return: always -1
 */
void print_error(char *cmd, int counter)
{
	char *er;

	PRINTER("hsh");
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(cmd);
	PRINTER(": not found\n");
}
