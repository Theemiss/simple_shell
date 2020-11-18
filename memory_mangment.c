#include "shell.h"

/**
 **_realloc -  a function that reallocates a memory block using malloc and free
 *@ptr: pointer
 *@old_size: int
 *@new_size: int
 *Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * free_array - free an array
 * @tokens:array
 *Return: void
 */
void free_array(char **tokens)
{
	unsigned int i = 1;

	if (tokens == NULL)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
}
/**
 * _memcpy - copy byte from src to dest
 * @dest: dest
 * @src:src
 * @n:size
 *Return: void
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fill_an_array - fill an array
 * @a:void
 * @el:int
 * @len:len int
 *Return: void
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc - a function that allocates memory for an array, using malloc.
 * @size: int
 * Return: pointer to an array
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
