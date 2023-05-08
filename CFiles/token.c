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

void	get_word(t_token *token, char *str)
{
	int size_of_word;
	int	i;
    t_token *tmp;

	size_of_word = 0;
	i = 0;
    tmp = token;
	while (i < ft_strlen(str))
	{
		if (excluded_char(str[i]) == 0)
		{
			while (excluded_char(str[i]) == 0 && str[i] != endline)
			{
                //printf("%c", str[i]);
				size_of_word ++;
				i ++;
			}
		}
        if (excluded_char(str[i - 1]) == 0 && i != 0)
        {
            tmp->type = size_of_word + 1;
            tmp = tmp->next;
        }
		size_of_word = 0;
		i ++;
	}
}

void	init_token(t_token **token, char *str)
{
	int i;

	i = 0;
	while (i < get_total_token(str) - 1)
	{
		ft_lst_add_backs(token, create_new());
		i ++;
	}
	get_word(*token, str);
} 