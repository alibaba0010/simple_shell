#include "shell.h"

/**
 * get_path - Retrieves the value of the PATH environment variable.
 *
 * Return: Pointer to the value of the PATH environment variable.
 */
char *get_path(void)
{
    return (_getenv("PATH"));
}

