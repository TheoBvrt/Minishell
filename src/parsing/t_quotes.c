/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_quotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2024/02/07 12:18:38 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	while_test(t_cmd *cmd, char quote)
{
	char	cmd_0;
	char	cmd_1;

	cmd_0 = cmd->cmd[0];
	cmd_1 = cmd->prev->cmd[0];
	if (cmd && (cmd_0 != quote || (cmd->prev && cmd_1 == '\\')))
		return (0);
	else
		return (1);
}

char	*create_string_node(t_cmd *cmd, char quote)
{
	char	*returned_str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!cmd)
		return (NULL);
	returned_str = malloc(len_cmd(cmd, quote) + 1);
	if (!returned_str)
		return (NULL);
	i = 0;
	while (while_test(cmd, quote) == 0)
	{
		len = ft_strlen(cmd->cmd);
		ft_memcpy(returned_str + i, cmd->cmd, len);
		i += len;
		cmd = cmd->next;
	}
	returned_str[i] = '\0';
	return (returned_str);
}

void	quotes_parser(t_shell *shell)
{
	t_cmd	*current;
	char	current_quote;
	char	*new_str;

	current = shell->cmd;
	while (current)
	{
		if (current->cmd[0] == '\"' || current->cmd[0] == '\'')
		{
			current_quote = current->cmd[0];
			current = ft_pop(current, shell);
			new_str = create_string_node(current, current_quote);
			while (current->cmd[0] != current_quote)
				current = ft_pop(current, shell);
			free(current->cmd);
			current->cmd = new_str;
		}
		current = current->next;
	}
}
