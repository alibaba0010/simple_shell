#include "shell.h"

/**
 * print_to_stdout - Prints a string to the standard output stream
 * @string: The string to print
 *
 * Return: void
 */
void print_to_stdout(char *string)
{
    size_t length;
    ssize_t num_written;

    length = _strlen(string);
    num_written = write(STDOUT_FILENO, string, length);
    if (num_written == -1)
    {
        perror("write");
    }
}

/**
 * print_to_stderr - Prints an error message to the standard error stream
 * @error_msg: The error message to print
 *
 * Return: void
 */
void print_to_stderr(char *error_msg)
{
    size_t length;
    ssize_t num_written;

    length = _strlen(error_msg);
    num_written = write(STDERR_FILENO, error_msg, length);
    if (num_written == -1)
    {
        perror("write");
    }
}

