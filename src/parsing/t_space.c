/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_space.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_redir(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	else
		return (0);
}

void	remove_other_space(t_shell *shell)
{
	t_cmd	*current;

	current = shell->cmd;
	while (current)
	{
		if (test_redir(current->cmd[0]))
		{
			if (current->prev != NULL && current->prev->cmd[0] == ' ')
			{
				current = current->prev;
				current = ft_pop(current, shell);
			}
			if (current->next != NULL && current->next->cmd[0] == ' ')
			{
				current = current->next;
				current = ft_pop(current, shell);
			}
		}
		current = current->next;
	}
}

void	remove_space(t_shell *shell)
{
	t_cmd	*current;
	char	quote;
	char	matching_quote;

	current = shell->cmd;
	while (current)
	{
		quote = current->cmd[0];
		if (quote == '\'' || quote == '\"')
		{
			matching_quote = quote;
			while (current && current->cmd[0] != matching_quote)
				current = current->next;
		}
		else if (quote == ' ' && current->next && current->next->cmd[0] == ' ')
		{
			current = ft_pop(current, shell);
			continue ;
		}
		current = current->next;
	}
	remove_other_space(shell);
}
