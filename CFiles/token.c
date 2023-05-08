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

void	get_token(t_token *token, char *str)
{
	int size_of_word;
	int	i;
    int t;
    t_token *tmp;
    t_token  *tmp2;

	size_of_word = 0;
	i = 0;
    t = 0;
    tmp = token;
    tmp2 = token;
	while (i < ft_strlen(str))
	{
		if (excluded_char(str[i]) == 0)
		{
			while (excluded_char(str[i]) == 0 && str[i] != endline)
			{
				size_of_word ++;
				i ++;
			}
		}
        if (excluded_char(str[i - 1]) == 0 && i != 0)
        {
            tmp->str = ft_calloc(size_of_word + 1, sizeof(char));
            tmp = tmp->next;
        }
		size_of_word = 0;
		i ++;
	}
    i = 0;

    while (i < ft_strlen(str))
    {
        if (excluded_char(str[i]) == 0)
        {
            while (excluded_char(str[i]) == 0 && str[i] != endline)
                tmp2->str[t++] = str[i]++;
            tmp2 = tmp2->next;
            t = 0;
        }
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
	get_token(*token, str);
} 