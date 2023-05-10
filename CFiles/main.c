#include "../Include/minishell.h"

void	setup(t_exec **exec, char *str)
{
	init_token(exec, str);
}

int	main(int argc, char **argv)
{
    t_exec *exec;

	exec = malloc(sizeof(t_exec));
    exec->test = 0;
	setup(&exec, argv[1]);
    ft_print_list(exec);
	return (0);
}