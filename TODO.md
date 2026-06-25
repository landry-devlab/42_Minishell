# TODO

- allocate memory for cmd struct in parsing
- handle signals
- implement all builtin functions
- loop through all cmds in execute_prompt
- search for an external binary in the current directory and through PATH
- free all cmd in cleanup free_data (it frees only the first cmd now)
- collect the env on the minishell start
- implement history
- handle redirections and split the user prompt to blocks regarding | < > << >>

## Landry
- modify the error_message function management
-- Sergii: Why the current implementation is not sufficient? How should a new implementation behave?
- evolution of the split function to tokenize and be able to organise the structure for redirrection
-- Sergii: I'm proposing to write the todo elements in a way so it will be clear how to verify it or how it should work. This way it will simplify switching for us.
-- Sergii: do we need to integrate ft_printf, if we can use printf? I'd like to keep the project as simple as possible?

# DONE

- Integrate libft
- Initialization function for the global variable
