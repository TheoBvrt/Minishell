/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2023/06/09 10:11:06 by marvin           ###   ########.fr       */
/*   Updated: 2023/06/08 15:48:47 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_inside_node(t_variable *env)
{
	free(env->name);
	env->name = NULL;
	free(env->value);
	env->value = NULL;
}

void	free_node(t_variable **env, t_variable **head)
{
	t_variable	*tmp;

	free_inside_node(*env);
	tmp = NULL;
	if (!*env)
		return ;
	if (!(*env)->next)
	{
		tmp = (*env)->prev;
		tmp->next = NULL;
	}
	else if (!(*env)->prev)
	{
		tmp = (*env)->next;
		tmp->prev = NULL;
		*head = tmp;
	}
	else
	{
		tmp = (*env)->prev;
		tmp->next = (*env)->next;
	}
	free(*env);
	*env = tmp;
}

void	unset(char **args, t_variable **env_tmp)
{
	t_variable	*env;
	int			i;

	i = 0;
	while (args[i])
	{
		env = *env_tmp;
		while (env)
		{
			if (args[i] && ft_strcmp(env->name, args[i]) == 0)
			{
				free_node(&env, env_tmp);
				break ;
			}
			env = env->next;
		}
		i++;
	}
}
