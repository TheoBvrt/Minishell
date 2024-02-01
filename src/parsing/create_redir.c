/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*basic_redir(t_redir **redir, t_cmd *tmp)
{
	if (tmp->next && tmp->next->cmd[0] == '>')
		redir_add_back(redir, redir_create(tmp->next->next->cmd, 1, NULL));
	else
		redir_add_back(redir, redir_create(tmp->next->cmd, 0, NULL));
	while (tmp->cmd[0] == '>')
		tmp = tmp->next;
	return (tmp);
}

t_cmd	*zebi_redir(t_redir **redir, t_cmd *tmp)
{
	if (tmp->next && tmp->next->cmd[0] == '<')
		redir_add_back(redir, here_doc(tmp, tmp->next->next->cmd));
	else
		redir_add_back(redir, redir_create(tmp->next->cmd, 2, NULL));
	while (tmp->cmd[0] == '<')
		tmp = tmp->next;
	return (tmp);
}

t_redir	*redirection(t_redir *redir, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->cmd[0] == '>')
			tmp = basic_redir(&redir, tmp);
		else if (tmp->cmd[0] == '<')
			tmp = zebi_redir(&redir, tmp);
		if (tmp->cmd[0] == '|')
			break ;
		tmp = tmp->next;
	}
	return (redir);
}

t_redir	*create_redir(t_cmd	*cmd)
{
	t_redir	*redir;
	t_cmd	*tmp;

	redir = NULL;
	tmp = cmd;
	redir = redirection(redir, tmp);
	return (redir);
}
