/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Check is le character est un token
/// \param c character a checker
/// \return 1 si c'est un token 0 si non
int	is_token(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '"')
		return (1);
	else if (c == '\'')
		return (1);
	else if (c == '\\')
		return (1);
	else if (c == '>')
		return (1);
	else if (c == '<')
		return (1);
	return (0);
}

/// Compte les arguments afin de pouvoir creer la taille d'un **char
/// \param shell Structure shell
/// \return nb d'arguments
int	count_args(t_cmd *tmp)
{
	int	count;

	count = 0;
	if (lst_len(tmp) == 1)
		return (1);
	while (tmp && (tmp->cmd[0] == '<'
			|| tmp->cmd[0] == '>' || tmp->cmd[0] == '|'))
		tmp = tmp->next;
	while (tmp && tmp->cmd[0] != '<'
		&& tmp->cmd[0] != '>' && tmp->cmd[0] != '|')
	{
		if (tmp->prev && tmp->prev->cmd[0] != '<'
			&& tmp->prev->cmd[0] != '>' && tmp->cmd[0] != ' ')
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_specific_quotes(t_shell *shell, char c, char quotes)
{
	int		count;
	t_cmd	*tmp;

	tmp = shell->cmd;
	count = 0;
	while (tmp)
	{
		if (tmp->cmd[0] == quotes)
		{
			if (tmp->next)
				tmp = tmp->next;
			while (tmp->next)
			{
				if (tmp->cmd[0] == quotes)
					break ;
				tmp = tmp->next;
			}
		}
		if (tmp->cmd[0] == c)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_quotes(t_shell *shell)
{
	if (check_specific_quotes(shell, '"', '\'') % 2 == 0
		&& check_specific_quotes(shell, '\'', '"') % 2 == 0)
		return (1);
	return (0);
}

void	read_first_token(t_shell *shell)
{
	lst_add_back(&shell->cmd, lst_create(ft_substr(shell->read, 0, 1)));
}
