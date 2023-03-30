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

void	get_token(t_token **token, char *str)
{
	int i;

	i = 0;
	while (i < get_total_token(str))
	{
		list_add_back(token);
		i ++;
		printf("test\n");
	}
}