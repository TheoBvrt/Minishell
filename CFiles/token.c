#include "../Include/minishell.h"

int	excluded_char(char c)
{
	if (c == 9 || c == 32)
		return (1);
	else
		return (0);
}

int	get_total_token(char *str)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	if (excluded_char(str[0]) == 0 && str[i] != endline)
		total ++;
	while (str[i] != endline)
	{
		if (excluded_char(str[i]) == 1)
			i ++;
		if (excluded_char(str[i]) == 0 && excluded_char(str[i - 1]) == 1 && str[i] != endline)
			total ++;
		i ++;
	}
	return (total);
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

void	get_token(t_token **token, char *str)
{
	int i;

	i = 0;
	while (i < get_total_token(str))
	{
		ft_lst_last_2(token, create_new());
		i ++;
	}
}