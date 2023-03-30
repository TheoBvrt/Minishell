#include "../Include/minishell.h"

void	setup(t_token **token, char *str)
{
	get_token(token, str);
}

int	main(int argc, char **argv)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	setup(&token, argv[1]);

	printf("%d\n", token->type);
	token = token->next;
	printf("%d\n", token->type);
	token = token->next;
	printf("%d\n", token->type);
	return (0);
}