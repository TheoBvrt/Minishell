#include "../Include/minishell.h"

void	list_add_back(t_token **lst)
{
    t_token *new;

    new = malloc(sizeof(t_token));
    int r = rand() % 20;
    new->type = r;
    if (lst == NULL)
    {
        *lst = new;
        return ;
    }
    else
    {
        t_token *tmp;

        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
        *lst = tmp;
    }
}