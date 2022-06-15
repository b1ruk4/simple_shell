#include "main.h"

/**
* print_s - prints a string
* @s: string to be printed
*
* Return: number of characters printed
*/
int print_s(char *s)
{
	int k = 0;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[k] != '\0')
	{
		_putchar(s[k]);
		k++;
	}

	return (k);
}

