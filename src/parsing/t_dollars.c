#include "minishell.h"

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
				//
				break;
			}
			i ++;
		}
		current = current->next;
	}
}