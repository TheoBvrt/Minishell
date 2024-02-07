/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2024/02/07 12:18:41 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable	*create_env(char *name, char *value)
{
	t_variable	*tmp;

	tmp = malloc(sizeof(t_variable));
	tmp->name = ft_strdup(name);
	if (value)
		tmp->value = ft_strdup(value);
	else
		tmp->value = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	env_add_back(t_variable **env, t_variable *new)
{
	t_variable	*current;

	if (*env == NULL)
		*env = new;
	else
	{
		current = *env;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
}

void	add_to_env(char **args, t_shell *shell)
{
	t_variable	*env;
	t_variable	*head;

	env = shell->env;
	head = shell->env;
	while (env)
	{
		if ((ft_strcmp(env->name, args[0]) == 0))
		{
			free(env->value);
			env->value = NULL;
			if (args[1])
				env->value = ft_strdup(args[1]);
			return ;
		}
		env = env->next;
	}
	shell->env = head;
	if (args[1])
		env_add_back(&shell->env, create_env(args[0], args[1]));
	else
		env_add_back(&shell->env, create_env(args[0], NULL));
}

char	*get_env_value(t_shell *shell, char *str)
{
	t_variable	*env;

	env = shell->env;
	if (!str)
		return ("");
	if (!ft_strcmp(str, "?"))
		return (ft_itoa(g_error_num));
	while (env)
	{
		if (!ft_strcmp(env->name, str))
			return (env->value);
		env = env->next;
	}
	return ("");
}
