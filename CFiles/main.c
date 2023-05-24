#include "../Include/minishell.h"

void	setup(t_exec **exec, char *str)
{
	init_token(exec, str);
	//ft_printf("(nb_of_redir : %d)\n", check_redir(1, str));
	//ft_printf("nb of words : %d)\n", word_count(1, str));
}

int	main(int argc, char **argv)
{
    t_exec *exec;

	exec = malloc(sizeof(t_exec));
    exec->node_id = 0;
	setup(&exec, argv[1]);
    ft_print_list(exec);
	return (0);
}