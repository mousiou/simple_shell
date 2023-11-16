#include "shell.h"
/**
 * is_builtin - This function checks if a
 * given command is a built-in command.
 * @command: the name of the command to check.
 * Return: 1 if the command is a built-in
 * command, and 0 otherwise.
 */
int is_builtin(char *command)
{
char *builtins[] = {
"exit", "env", "setenv", "cd", NULL
};
int i;

for (i = 0; builtins[i]; i++)
{
if (_strcmp(command, builtins[i]) == 0)
	return (1);
}
return (0);
}
/**
 * handle_builtin - This function handles built-in commands.
 * @command: an array of strings that is used
 * to store the name of the program that
 * is being executed and any arguments that it was given.
 * @argv: an array of strings that is used to store
 * the arguments that were passed to the program.
 * @status: a pointer to an integer that is used to store
 * the exit status of the program.
 * @idx: the index of the current command in the command
 * line history.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
(void) argv;
(void)idx;

if (_strcmp(command[0], "exit") == 0)
{
exit_shell(command, status);
}
else if (_strcmp(command[0], "env") == 0)
{
print_env(command, status);
}
}
/**
 * exit_shell - This function exits the shell.
 * @command: an array of strings that is used
 * to store the name of the program that
 * is being executed and any arguments that it was given.
 * @status: a pointer to an integer that
 * is used to store the exit status of the program.
 */
void exit_shell(char **command, int *status)
{
freearr(command);
exit(*status);
}
/**
 * print_env - This function prints the current
 * environment to the standard output.
 * @command: an array of strings that is used
 * to store the name of the program that
 * is being executed and any arguments that it was given.
 * @status: a pointer to an integer that
 * is used to store the exit status of the program.
 */
void print_env(char **command, int *status)
{
int i;

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freearr(command);
(*status) = 0;
}
