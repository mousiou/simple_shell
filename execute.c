#include "shell.h"
/**
 * _execute - this function Executes a command using
 * the fork() and execve() system calls
 * @command: pointer to an array of character pointers,
 * each representing a command or argument.
 * @argv: pointer to an array of character pointers.
 * @idx: an integer representing the current command index.
 * Return: the exit status of the executed child process.
 */
int _execute(char **command, char **argv, int idx)
{
char *full_cmd;
pid_t child;
int status;

full_cmd = _getpath(command[0]);
if (!full_cmd)
{
print_error(argv[0], command[0], idx);
freearr(command);
return (127);
}

child = fork();
if (child == 0)
{
if (execve(full_cmd, command, environ) == -1)
{
free(full_cmd), full_cmd = NULL;
freearr(command);
}
}
else
{
waitpid(child, &status, 0);
freearr(command);
free(full_cmd), full_cmd = NULL;
}
return (WEXITSTATUS(status));
}
