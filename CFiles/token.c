#include "../Include/minishell.h"

int	excluded_char(char c)
{
	if (c == 9 || c == 32)
		return (1);
	else
		return (0);
}

int	get_total_exec_node(char *str)
{
    int total;
    int i;

    total = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '|')
            total ++;
        i ++;
    }
	return (++total);
}

void	get_token(t_exec *exec, char *str)
{
	t_exec *tmp;
    int i;

	tmp = exec;
	i = 0;
	while (str[i] != endline)
	{
		i ++;
	}
	
}

void	init_token(t_exec **exec, char *str)
{
	int i;

	i = 0;
	while (i < get_total_exec_node(str) - 1)
	{
		ft_lst_add_backs(exec, create_new());
		i ++;
    }
	get_token(*exec, str);
} 