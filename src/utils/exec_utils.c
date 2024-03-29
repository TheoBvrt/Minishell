/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2024/02/07 12:18:44 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Creer un element de la linked list
/// \param args commande et arguments
t_exec	*exec_create(char **args, t_redir *redir)
{
	t_exec	*exec;

	exec = malloc(sizeof(t_exec));
	exec->cmd_args = args;
	exec->redir = redir;
	exec->next = NULL;
	exec->prev = NULL;
	return (exec);
}

/// Ajoute a la fin de la linked list
/// \param lst Linked list qui va contenir le nouveau element
/// \param new Linked list a ajouter
void	exec_add_back(t_exec **exec, t_exec *new)
{
	t_exec	*current;
	t_exec	*tmp_previous;

	if (*exec == NULL)
		*exec = new;
	else
	{
		tmp_previous = *exec;
		current = *exec;
		while (current->next)
		{
			tmp_previous = current;
			current = current->next;
		}
		current->next = new;
		current->prev = tmp_previous;
	}
}
