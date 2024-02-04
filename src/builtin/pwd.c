/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_shell *shell)
{
	t_variable	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == 0)
		{
			ft_printf("%s\n", tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
}
