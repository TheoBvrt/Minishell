#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*next;
} t_token;

void free_list(void	**list);
void get_token(t_token **token);

#endif