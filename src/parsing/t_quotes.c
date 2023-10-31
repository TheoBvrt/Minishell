#include "minishell.h"

char *create_string_node(t_cmd *cmd, char quote) {
	char	*returned_str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!cmd)
		return NULL;
	returned_str = malloc(len_cmd(cmd, quote) + 1);
	if (!returned_str) 
		return NULL;
	i = 0;
	while (cmd && (cmd->cmd[0] != quote || (cmd->prev && cmd->prev->cmd[0] == '\\')))
	{
		len = ft_strlen(cmd->cmd);
		ft_memcpy(returned_str + i, cmd->cmd, len);
		i += len;
		cmd = cmd->next;
	}
	returned_str[i] = '\0';
	return returned_str;
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