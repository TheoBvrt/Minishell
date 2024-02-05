/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	utils_1(t_shell *shell, int x, int i)
{
	lst_add_back(&shell->cmd, lst_create(ft_substr(\
		shell->read, x, i - x + 1)));
}

void	utils_2(t_shell *shell, int x, int i)
{
	lst_add_back(&shell->cmd, lst_create(ft_substr(\
		shell->read, x, 1)));
}

t_cmd	*parse_read_line(t_shell *shell)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (shell->read[i] != '\0')
	{
		if (i == 0 && is_token(shell->read[i]))
		{
			read_first_token(shell);
			x ++;
		}
		if (is_token(shell->read[i + 1]) || !shell->read[i + 1])
		{
			if ((i - x + 1) > 0)
				utils_1(shell, x, i);
			x = i + 1;
			if (shell->read[x] != 0)
				utils_2(shell, x, i);
			x ++;
		}
		i ++;
	}
	return (shell->cmd);
}

void	error_msg(t_shell *shell, char *msg)
{
	free_cmd(shell);
	printf("%s\n", msg);
}

void	parse_cmd(t_shell *shell)
{
	remove_space(shell);
	dollars_parser(shell);
	quotes_parser(shell);
	create_command(shell);
}
