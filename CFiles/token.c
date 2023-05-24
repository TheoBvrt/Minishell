#include "../Include/minishell.h"

int	excluded_char(char c)
{
	if (c == 9 || c == 32)
		return (1);
	else
		return (0);
}

int redir_checker(char c_1, char c_2)
{
	if (c_1 == '>' && (excluded_char(c_2) == 1 || c_2 == '\0' || c_2 == '|'))
		return (right);
	if (c_1 == '<' && (excluded_char(c_2) == 1 || c_2 == '\0' || c_2 == '|'))
		return (left);
	if (c_1 == '>' && c_2 == '>')
		return (right_shift);
	if (c_1 == '<' && c_2 == '<')
		return (left_shift);
	else
		return (-1);
}

int		check_all_redir(char *str)
{
	int	index;

	index = 0;
	while (str[index] != endline)
	{
		if (redir_checker(str[index], str[index + 1]) != -1)
		{
			//
		}
		index ++;
	}
	return (0);
}

int check_redir(int node_id, char *str)
{
	int total_redir;
	int	index;
	int pipe_passed;

	total_redir = 0;
	index = 0;
	pipe_passed = 0;
	if (node_id == 0)
    {
		while (str[index] != endline && str[index] != '|')
		{
			if (redir_checker(str[index], str[index + 1]) != -1)
			{
				total_redir ++;
				index ++;
			}
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
		while (str[index] != endline && str[index] != '|')
		{
			if (redir_checker(str[index], str[index + 1]) != -1)
			{
				total_redir ++;
				index ++;
			}
			index ++;
		}
		index ++;
	}
	return (total_redir);
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
			if (excluded_char(str[index]) == 0)
			{
				if (excluded_char(str[index - 1]) == 1 || index == 0)
					word_count ++;
			}
            index ++;
        }
		return (word_count);
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
			if (excluded_char(str[index]) == 0 && excluded_char(str[index - 1]) == 1)
				word_count ++;
            index ++;
        }
	}
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
	int total_cmd_args;

	i = 0;
	total_cmd_args = 0;
	node_id = 0;
	while (i < get_total_exec_node(str) - 1)
	{
		ft_lst_add_backs(exec, create_new(node_id));
		node_id ++;
		i ++;
    }
	node_id = 0;
	i = 0;

	while (i < get_total_exec_node(str))
	{
		total_cmd_args = word_count(node_id, str) - (check_redir(node_id, str)) * 2;
		printf("Total word count node %d : %d\n", node_id, total_cmd_args);
		i ++;
		node_id ++;
		total_cmd_args = 0;
	}
	get_token(*exec, str);
}