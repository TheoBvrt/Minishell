#include "minishell.h"

void	read_first_token(t_shell *shell)
{
	lst_add_back(&shell->cmd, lst_create(ft_substr(shell->read, 0, 1)));
}

t_cmd *parse_read_line(t_shell *shell)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (shell->read[i] != '\0')
	{
		if (i == 0 && is_token(shell->read[i])) {
			read_first_token(shell);
			x ++;
		}
		if (is_token(shell->read[i + 1]) || !shell->read[i + 1])
		{
			if ((i - x + 1) > 0)
			{
				lst_add_back(&shell->cmd, lst_create(ft_substr(
						shell->read, x, i - x + 1)));
			}
			x = i + 1;
			if (shell->read[x] != 0)
			{
				lst_add_back(&shell->cmd, lst_create(ft_substr(
						shell->read, x, 1)));
			}
			x ++;
		}
		i ++;
	}
	
	return (shell->cmd);
}