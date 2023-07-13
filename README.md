ALX Simple Shell Team Project

This is a collaborative project by the ALX team focused on creating a simple shell project that emulates the functionality of the Bash shell. Our shell is named hsh.

The project was implemented using the C language and adheres to the Shell Betty linter guidelines.

General Requirements for the Project:

- All files will be compiled on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89.
- All files should end with a new line.
- A mandatory README.md file should be included at the root of the project folder.
- The code should follow the Betty style, it will be checked using betty-style.pl and betty-doc.pl.
- The shell should not have any memory leaks.
- Each file should contain no more than 5 functions.
- All header files should have include guards.
- A README file should be written to describe the project.

Description:
hsh is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

Functions of hsh:
- Prints a prompt and waits for a command from the user.
- Creates a child process to handle the command.
- Checks for built-ins, aliases in the PATH, and local executable programs.
- The child process replaces itself with the command and accepts arguments.
- After the command execution is completed, the program returns to the parent process and prints the prompt, ready to receive a new command.
- To exit, the user can press Ctrl-D or enter "exit" (with or without a status).
- Works in both interactive and non-interactive mode.

Compilation:
To compile hsh, use the following command:

c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Invocation:

Usage: hsh [filename]

To invoke hsh, compile all the .c files in the repository and execute the resulting executable.

hsh can be invoked interactively or non-interactively. If hsh is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:

bash
$ echo "echo 'hello'" | ./hsh 'hello'

If hsh is invoked with standard input connected to a terminal (determined by isatty(3)), an interactive shell is opened. When running interactively, hsh displays the prompt $ when it is ready to read a command.

Example:
shell
$ ./hsh $
Alternatively, if command-line arguments are provided upon invocation, hsh treats the first argument as a file from which to read commands. The file should contain one command per line. hsh runs each command in order before exiting.

Example:
bash
$ cat test echo 'hello' $ ./hsh test 'hello'

Environment:
Upon invocation, hsh receives and copies the environment of the parent process in which it was executed. The environment is an array of name-value strings representing variables in the format NAME=VALUE. Some key environmental variables are:

HOME: The home directory of the current user and the default directory argument for the cd builtin command.
PWD: The current working directory set by the cd command.
OLDPWD: The previous working directory set by the cd command.
PATH: A colon-separated list of directories in which the shell looks for commands. A null directory name indicates the current directory.
Command Execution:
Upon receiving a command, hsh tokenizes it into words using spaces as delimiters. The first word is considered the command, and the remaining words are treated as arguments. The following actions are taken:

- If the first character of the command is neither a slash (/) nor a dot (.), the shell searches for it in the list of shell builtins. If a builtin command with that name is found, it is invoked.
- If the first character of the command is not a slash (/), nor dot (.), nor a builtin command, hsh searches each element of the PATH variable for a directory containing an executable file with the command name.
- If the first character of the command is a slash (/), dot (.), or either of the previous searches is successful, the shell executes the named program with any remaining arguments in a separate execution environment.

Exit Status:
hsh returns the exit status of the last executed command, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is 127. If a command is found but not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage.

Signals:
While running in interactive mode, hsh ignores the Ctrl+C keyboard input. Alternatively, pressing end-of-file (Ctrl+D) will exit the program.

Variable Replacement:
hsh interprets the $ character for variable replacement.

$ENV_VARIABLE: ENV_VARIABLE is substituted with its value.
$?: ? is substituted with the return value of the last executed program.
$$: The second $ is substituted with the current process ID.

Comments:
hsh ignores any words or characters preceded by the # character on a line.

Operators:
hsh interprets the following special operator characters:

;:- (Command separator): Commands separated by a ; are executed sequentially.
&& (AND logical operator): command1 && command2 - command2 is executed only if command1 returns an exit status of zero.
|| (OR logical operator): command1 || command2 - command2 is executed only if command1 returns a non-zero exit status.

Builtin Commands in hsh:
cd: Changes the current directory of the process.
alias: Handles aliases, Prints a list of all aliases, one per line.
exit: Exits the shell, the STATUS argument is the integer used to exit the shell. If no argument is given, the command is interpreted as exit 0.
env: Prints the current environment.
setenv: Initializes or modifies an environment variable. Upon failure, prints a message to stderr.
unsetenv: Removes an environment variable. Upon failure, prints a message to stderr.
What We Learned:

Understanding how a shell works and how it finds commands.
- Creating, forking, and managing processes.
Handling dynamic memory allocation in a large-scale project.
- Executing a program from another program.
- Pair programming and collaboration within a team.
- Building a test suite to ensure code quality.

