#include "../Include/minishell.h"

void	setup(t_token **token, char *str)
{
	init_token(token, str);
}

int	main(int argc, char **argv)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	setup(&token, argv[1]);
	ft_print_list(token);
	return (0);
}