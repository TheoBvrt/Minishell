#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

enum e_utils
{
	endline = '\0'
};

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next;
} t_token;

void	free_list(void	**list);
void	init_token(t_token **token, char *str);
t_token	*create_new();
void	list_add_back(t_token **lst);
void    ft_lst_add_backs(t_token **lst, t_token *new);
void    ft_print_list(t_token *l);
int		ft_is_empty_list(t_token *l);
t_token	*ft_lst_last_2(t_token *lst);

#endif