#include "../Include/minishell.h"

void	setup(t_token **token, char *str)
{
	get_token(token, str);
}

int    is_empty_list(t_token *l)
{
    return (l == NULL);
}

void    print_list(t_token *l)
{
    while (!is_empty_list(l))
    {    
        printf("%d ", l->type);
        l = l->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	setup(&token, argv[1]);
	print_list(token);
	return (0);
}