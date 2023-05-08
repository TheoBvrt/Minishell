#include "../Include/minishell.h"

int    ft_is_empty_list(t_token *l)
{
    return (l == NULL);
}

void    ft_print_list(t_token *l)
{
    while (!ft_is_empty_list(l))
    {    
        printf("%s\n", l->str);
        l = l->next;
    }
    printf("\n");
}

void    ft_lst_add_backs(t_token **lst, t_token *new)
{
    t_token    *tmp;

    if (!lst || !new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    tmp = ft_lst_last_2(*lst);
    tmp->next = new;
}
 
t_token	*create_new()
{
	t_token *new;

	new = malloc(sizeof(t_token));
	new->type = rand() % 20;
	return (new);
}
 
t_token	*ft_lst_last_2(t_token *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}