/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_create_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd *advance_past_pipe(t_cmd *cmd) {
    while (cmd && cmd->cmd[0] != '|')
        cmd = cmd->next;
    return (cmd);
}

int	is_not_redirection(t_cmd *cmd) {
    char	first_char;
    char	prev_first_char;

    first_char = cmd->cmd[0];
    if (cmd->prev)
    {
        prev_first_char = cmd->prev->cmd[0];
        if (prev_first_char == '<' || prev_first_char == '>')
            return 0;
    }
	return (!(first_char == '>' || first_char == '<' ||
		first_char == '|' || first_char == ' '));
}

char **build_cmd_args(t_cmd *cmd) {
    int		arg_count;
	char	**args;
	int		i;

	i = 0;
	arg_count = count_args(cmd);
    if (arg_count == 0)
		return NULL;
    args = malloc(sizeof(char *) * (arg_count + 1));
    if (!args)
		return NULL;
    while (cmd && i < arg_count)
	{
        if (is_not_redirection(cmd)) 
		{
            args[i] = ft_strdup(cmd->cmd);
            i++;
        }
        if (cmd->cmd[0] == '|')
			break;
        cmd = cmd->next;
    }
    args[i] = NULL;
    return (args);
}

void create_command(t_shell *shell)
{
    t_cmd	*current_cmd;
	t_redir	*redirect;
	char	**args;

	current_cmd = shell->cmd;
    while (current_cmd)
	{
        args = build_cmd_args(current_cmd);
    	redirect = create_redir(current_cmd);
        exec_add_back(&shell->exec, exec_create(args, redirect));
        current_cmd = advance_past_pipe(current_cmd);
        if (current_cmd)
			current_cmd = current_cmd->next;
    }
}
