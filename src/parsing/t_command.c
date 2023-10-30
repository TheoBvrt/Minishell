#include "minishell.h"

void	command_parser(t_shell *shell)
{
	remove_space(shell);
	dollars_parser(shell);
}