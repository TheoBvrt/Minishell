#include "minishell.h"

void	remove_space(t_shell *shell)
{
	t_cmd	*current;
	char	quote;
	char	matching_quote

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
            continue;
        }
        current = current->next;
    }
}