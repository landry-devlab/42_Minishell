# TODO

## Parsing
- parse double quotes properly
- allocate memory for cmd struct in parsing
- handle redirections and split the user prompt to blocks regarding | < > << >>
- Handle environment variables ($ followed by a sequence of characters) which should expand to their values
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.

## Execution
- Execution: exit only on the top level (in the run_terminil loop), not in the execution/parsing functions. 
- Update exit_code on execution external commands
- implement all builtin functions
  - export with no options
  - unset with no options
  - env with no options or arguments
- loop through all cmds in execute_prompt
- search for an external binary in the current directory and through PATH
- Implement the following redirections:
  - < should redirect input.
  - \> should redirect output.
  - << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - \>> should redirect output in append mode
- Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- change directory to HOME if not arguments provided in cd builtin command
- set env variables in cd builtin command:
  - OLDPWD The previous working directory as set by the cd command.
  - PWD    The current working directory as set by the cd command.

## Other
- handle signals
  - Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
  - In interactive mode:
    - ctrl-C displays a new prompt on a new line.
    - ctrl-D exits the shell.
    - ctrl-\ does nothing.
- implement history
- verify with valgrind and fix leaks

## Working on

### Landry
- modify the error_message function management
-- Sergii: Why the current implementation is not sufficient? How should a new implementation behave?
- evolution of the split function to tokenize and be able to organise the structure for redirrection
-- Sergii: I'm proposing to write the todo elements in a way so it will be clear how to verify it or how it should work. This way it will simplify switching for us.
-- Sergii: do we need to integrate ft_printf, if we can use printf? I'd like to keep the project as simple as possible?

### Sergii
- collect the env on the minishell start

# DONE
- change the builtin_command  with is_builtin_command
- free all cmd in cleanup free_data (it frees only the first cmd now)
- changed the s_data and cmd cleaning function (previous one exposed to segfault)
- changed g_data to s_data
- replaced space to tabs
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- exit with no optionsaqqq
- Initialization function for the global variable
- Integrate libft
