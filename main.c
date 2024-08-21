#include "shell.h"

/**
 * main - Implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
char *user_input;
char **command_args;
int execution_status;

	/* Register signal handlers */
signal(SIGINT, handle_sigint);
signal(SIGQUIT, handle_sigquit);
signal(SIGTSTP, handle_sigstp);

do {
	user_input = get_user_input();
	if (!user_input || !*user_input) /* EOF detected, exit the loop */
	break;

	command_args = tokenize_input(user_input);
	if (!command_args || !*command_args)
	{
	free(user_input);
	free_tokens(command_args);
	continue;
	}

	execution_status = execute_command(command_args);

	free(user_input);
	free_tokens(command_args);

	/* Set execution_status to 1 to continue the loop */
	execution_status = 1;
	} while (execution_status);

	return (EXIT_SUCCESS);
}
