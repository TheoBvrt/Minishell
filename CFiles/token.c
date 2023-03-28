#include "../Include/minishell.h"

int	exclued_char(char c)
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
	while (str[i] != endline)
	{
		i ++;
	}
	return (total);
}

void	get_token(t_token **token, char *str)
{
	printf("%d", get_total_token(str));
}