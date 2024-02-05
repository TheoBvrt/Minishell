/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:21 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check(int globale)
{
	if (globale == 13)
		return (0);
	else if (globale == 2)
		return (130);
	else
		return (g_error_num);
}

int	check_g_err(char *args, int lol)
{
	if (!ft_strcmp("$?", args) && lol == 1)
	{
		ft_printf("%d ", check(g_error_num));
		return (0);
	}
	else if (!ft_strcmp("$?", args) && lol == 2)
	{
		ft_printf("%d\n", check(g_error_num));
		return (0);
	}
	return (1);
}

void	printf_no_nl(char **args, int i)
{
	while (args[i + 1])
	{
		check_g_err(args[i], 1);
		ft_printf("%s ", args[i]);
		i++;
	}
}

void	echo(char **args)
{
	int	i;

	if (args[1] && !ft_strcmp("-n", args[1]))
	{
		i = 2;
		printf_no_nl(args, i);
		if (!check_g_err(args[i], 2))
			return ;
		ft_printf("%s", args[i]);
	}
	else
	{
		i = 1;
		while (args[i + 1])
		{
			check_g_err(args[i], 1);
			ft_printf("%s ", args[i]);
			i++;
		}
		if (!check_g_err(args[i], 2))
			return ;
		ft_printf("%s", args[i]);
		ft_printf("\n");
	}
}
