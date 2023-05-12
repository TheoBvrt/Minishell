#include "../Include/minishell.h"

int    ft_is_empty_list(t_exec *l)
{
    return (l == NULL);
}

void    ft_print_list(t_exec *l)
{
    int i;

    i = 0;
    while (!ft_is_empty_list(l))
    {    
        ft_printf("%d", l->node_id);
        if (l->next != NULL)
            ft_printf("\n");
        l = l->next;
    }
    printf("\n");
}

void    ft_lst_add_backs(t_exec **lst, t_exec *new)
{
    t_exec   *tmp;

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
 
t_exec 	*create_new(int node_id)
{
	t_exec *new;

	new = malloc(sizeof(t_exec));
    new->node_id = node_id;
	return (new);
}
 
t_exec 	*ft_lst_last_2(t_exec *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}