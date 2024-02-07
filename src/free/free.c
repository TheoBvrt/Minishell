/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2024/02/07 12:11:04 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_shell *shell)
{
	t_cmd	*lst;
	t_cmd	*lst_tmp;

	lst = shell->cmd;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->cmd);
		free(lst);
		lst = lst_tmp;
	}
	shell->cmd = NULL;
}

void	free_env(t_shell *shell)
{
	t_variable	*lst;
	t_variable	*lst_tmp;

	lst = shell->env;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->name);
		free(lst->value);
		free(lst);
		lst = lst_tmp;
	}
	shell->env = NULL;
}

void	free_redir(t_redir *redir)
{
	t_redir	*lst;
	t_redir	*lst_tmp;

	lst = redir;
	while (lst)
	{
		lst_tmp = lst->next;
		free(lst->here_doc);
		free(lst->file);
		free(lst);
		lst = lst_tmp;
	}
}

void	free_tab(t_exec *exec)
{
	int	i;

	i = 0;
	while (exec->cmd_args[i])
	{
		free(exec->cmd_args[i]);
		exec->cmd_args[i] = NULL;
		i++;
	}
	free(exec->cmd_args);
}

void	free_exec(t_shell *shell)
{
	t_exec	*tmp_exec;

	while (shell->exec)
	{
		tmp_exec = shell->exec->next;
		if (shell->exec->redir)
			free_redir(shell->exec->redir);
		if (shell->exec->cmd_args)
			free_tab(shell->exec);
		free(shell->exec);
		shell->exec = NULL;
		shell->exec = tmp_exec;
	}
}
