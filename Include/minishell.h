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
void	get_token(t_token **token, char *str);

#endif