#include "shell.h"
/**
 * freearr - This function frees a dynamically
 * allocated array of strings.
 * @arr: the pointer to the array of strings.
 */
void freearr(char **arr)
{
int i;
if (!arr)
{
return;
}
for (i = 0; arr[i]; i++)
{
free(arr[i]);
arr[i] = NULL;
}
free(arr), arr = NULL;
}

/**
 * print_error - This function prints an error message
 * to the standard error output.
 * @name: the name of the file or
 * program that encountered the error.
 * @cmd: the command that was being
 * executed when the error occurred.
 * @idx: an index that provides additional
 * information about the error.
 */
void print_error(char *name, char *cmd, int idx)
{
char *index, mssg[] = ": not found\n";

index = _itoa(idx);

write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2));
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, ": ", 2));
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, mssg, _strlen(mssg));
free(index);
}

/**
 * _itoa - This function converts
 * an integer to a string representation.
 * @n: the integer to be converted
 * Return: a pointer to a character array
 * containing the string representation of the integer.
 */
char *_itoa(int n)
{
char buffer[20];
int i = 0;

if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}
buffer[i] = '\0';
reverse_string(buffer, i);
return (_strdup(buffer));
}

/**
 * reverse_string - this function reverses the array.
 * @str: the character array.
 * @len: array length.
 * Return: nothing as it directly modifies the input string.
 */
void reverse_string(char *str, int len)
{
char tmp;
int start = 0;
int end = len - 1;

while (start < end)
{
tmp = str[start];
str[start] = str[end];
str[end] = tmp;
start++;
end--;
}
}
