#include <stdio.h>
/**
 * print_s - prints a string
 * @s: string to be printed
 * Return: Always 0 (Success)
 */
int print_s(char *s)
{
int x = 0;

while (s[x] != '\0')
{
_putchar(s[x]);
x++;
}
return (x);
}
