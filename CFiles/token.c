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

int		word_count(int node_id, char *str)
{
	int	word_count;
	int	pipe_passed;
	int	index;

	word_count = 0;
	pipe_passed = 0;
	index = 0;

	if (node_id == 0)
	{
        while (str[index] != '|' && str[index] != endline)
        {
            ft_printf("%c", str[index]);
            index ++;
        }
	}
	else
	{
		while (pipe_passed != node_id)
		{
			if (str[index] == '|')
				pipe_passed ++;
			index ++;
		}
        while (str[index] != '|' && str[index] != endline)
        {
            ft_printf("%c", str[index]);
            index ++;
        }
	}
    ft_printf("\n");
	return (word_count);
}

void	get_token(t_exec *exec, char *str)
{
	t_exec *tmp;
    int i;
	int s;
	int word_size;

	tmp = exec;
	i = 0;
	s = 0;
	word_size = 0;
}

void	init_token(t_exec **exec, char *str)
{
	int i;
	int node_id;

	i = 0;
	node_id = 1;
	while (i < get_total_exec_node(str) - 1)
	{
		ft_lst_add_backs(exec, create_new(node_id));
		node_id ++;
		i ++;
    }
	get_token(*exec, str);
} 