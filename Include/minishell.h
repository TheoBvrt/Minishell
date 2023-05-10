#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

enum e_utils
{
	endline = '\0'
};

typedef struct s_exec
{
    char            **cmd_args;
    struct t_redir    *redir;
    struct s_exec    *next;
    struct s_exec    *prev;
    int test;
}    t_exec;

typedef struct s_redir
{
    char            *file;
    char            *Heredoc_args;
    struct s_redir    *next;
    struct s_redir    *prev;
    int                cases;
}    t_redir;

void	free_list(void	**list);
void	init_token(t_exec **exec, char *str);
t_exec 	*create_new();
void	list_add_back(t_exec **lst);
void    ft_lst_add_backs(t_exec **lst, t_exec *new);
void    ft_print_list(t_exec *l);
int		ft_is_empty_list(t_exec *l);
t_exec 	*ft_lst_last_2(t_exec *lst);

#endif