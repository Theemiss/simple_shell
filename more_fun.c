#include "shell.h"
/**
 * _strcpy - copies  src to  dest.
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - locate a character in a string
 * @s:string
 * @c:char
 * Return:pointer to char*
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * _strncmp - compares (n) amount of characters of two strings.
 * @s1: A string.
 * @s2: A string.
 * @n: Amount of characters to compare.
 *
 * Return: 1 if the strings don't match otherwise return 0.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - aloc new size for char
 *
 * @str:char*
 * Return: char*
 */
char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
	{
		free(str);
		return (NULL);
	}

	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
	{
		free(dupl);
		return (NULL);
	}
	_strcpy(dupl, str);
	free(str);
	return (dupl);
}
