/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dollars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(t_shell *shell, char *str)
{
	t_variable	*env;

	env = shell->env;
	if (!str)
		return ("");
	if (!ft_strcmp(str, "?"))
		return (ft_itoa(g_error_num));
	while (env)
	{
		if (!ft_strcmp(env->name, str))
			return (env->value);
		env = env->next;
	}
	return ("");
}

char	*value(t_shell *shell, char *cmd, int i)
{
	char	*str;
	char	*env;
	char	*tmp;

	if (cmd[1] && cmd[1] == '?' && !cmd[2])
		return (cmd);
	str = ft_substr(cmd, i + 1, ft_strlen(cmd) - i);
	env = get_value(shell, str);
	free(str);
	tmp = ft_substr(cmd, 0, i);
	str = ft_strjoin(tmp, env);
	free(cmd);
	free(tmp);
	return (str);
}

void	dollars_parser(t_shell *shell)
{
	t_cmd	*current;
	int		i;
	int		is_in_quote;

	current = shell->cmd;
	is_in_quote = 0;
	while (current)
	{
		i = 0;
		while (current->cmd[i])
		{
			if (current->cmd[i] == '\'' && is_in_quote == 0)
				is_in_quote = 1;
			else if (current->cmd[i] == '\'' && is_in_quote == 1)
				is_in_quote = 0;
			else if (current->cmd[i] == '$' && is_in_quote == 0)
			{
				current->cmd = value(shell, current->cmd, i);
				break;
			}
			i ++;
		}
		current = current->next;
	}
}