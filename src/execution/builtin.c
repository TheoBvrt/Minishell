/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:44:25 by asouchet          #+#    #+#             */
/*   Updated: 2024/02/07 12:12:55 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	c_args(char **cmd_args)
{
	int	count;

	count = 0;
	while (cmd_args[count] != NULL)
	count++;
	return (count);
}

int	builtin_in_fork(t_shell *shell, char *cmd, t_exec *tmp)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0 && c_args(tmp->cmd_args) == 1)
		printf("\n");
	else if (ft_strcmp(cmd, "echo") == 0 && c_args(tmp->cmd_args) > 1)
		echo(tmp->cmd_args);
	else if (ft_strcmp(cmd, "env") == 0)
		env(shell);
	else if (ft_strcmp(cmd, "pwd") == 0)
		pwd(shell);
	else
		return (1);
	return (0);
}

int	builtin_out_fork(t_shell *shell, char *cmd, t_exec *tmp)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		cd(shell, tmp->cmd_args);
	else if (ft_strcmp(cmd, "exit") == 0)
		ft_exit(shell, tmp->cmd_args);
	else if (ft_strcmp(cmd, "export") == 0)
		ft_export(shell, tmp->cmd_args);
	else if (ft_strcmp(cmd, "unset") == 0)
		unset(tmp->cmd_args, &(shell->env));
	else
		return (1);
	return (0);
}
