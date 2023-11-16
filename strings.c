#include "shell.h"
/**
 * _strdup - this function Creates a duplicate copy
 * of the given string
 * @str: pointer to the string to be duplicated.
 * Return: pointer to the newly created duplicate string.
 */
char *_strdup(const char *str)
{
char *ptr;
int i, len = 0;

if  (str == NULL)
{
return (NULL);
}
while (*str != '\0')
{
len++;
str++;
}
str = str - len;
ptr = malloc(szeof(char) * (len + 1));
if (ptr == NULL)
{
return (NULL);
}
for (i = 0; i <= len; i++)
{
ptr[i] = str[i];
}
return (ptr);
}

/**
 * _strcmp -  function that compares two strings.
 * @s1: primera cadena.
 * @s2: segunda cadena.
 * Return: 0.
 */

int _strcmp(char *s1, char *s2)
{
int cmp;

cmp = (int)*s1 - (int)*s2;
while (*s1)
{
if (*s1 != *s2)
{
break;
}
s1++;
s2++;
cmp = (int)*s1 - (int)*s2;
}
return (cmp);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
int len = 0;

while (s[len])
{
len++;
}
return (len);
}

/**
 * _strcat - function that concatenates two strings.
 * @src: cadena a copiar
 * @dest: destino de la cadena.
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
char *p = dest;

while (*p)
{
p++;
}
while (*src)
{
*p = *src;
p++;
src++;
}
*p = *src;
return (dest);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
