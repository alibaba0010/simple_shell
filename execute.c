#include "shell.h"

/**
 * execute_command - Execute a command with arguments.
 * @command_args: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute_command(char **command_args)
{
    pid_t child_pid;
    int exit_status = 0;
    char *cmd_path, *envp[2];

    if (command_args == NULL || *command_args == NULL)
        return (exit_status);

    if (check_for_builtin(command_args))
        return (exit_status);

    child_pid = fork();
    if (child_pid < 0)
    {
        _puterror("fork");
        return (1);
    }
    else if (child_pid == 0) // Child process
    {
        // Prepare environment variables for execve
        envp[0] = get_path();
        envp[1] = NULL;

        cmd_path = NULL;
        if (command_args[0][0] != '/')
            cmd_path = find_in_path(command_args[0]);

        if (cmd_path == NULL)
            cmd_path = command_args[0];

        if (execve(cmd_path, command_args, envp) == -1)
        {
            perror(command_args[0]);
            free_tokens(command_args);
            free_last_input();
            exit(EXIT_FAILURE);
        }
    }
    else // Parent process
    {
        int status;
        do
        {
            // Wait for the child process to complete
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        // Set exit status to the status returned by the child process
        exit_status = status;
    }

    return exit_status;
}

