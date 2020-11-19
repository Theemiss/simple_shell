#include "shell.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	_putchar('$');
	_putchar(' ');
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * Return: Void
 */
void print_error(char *input, int counter)
{
	char *er;

	PRINTER("hsh");
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
