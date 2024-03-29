/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2024/02/07 12:18:43 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_variable(t_variable *node, char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	node->name = ft_strlendup(s, i);
	s += i;
	if (!*s)
	{
		node->value = NULL;
		return ;
	}
	s++;
	i = 0;
	while (s[i])
		i++;
	node->value = ft_strlendup(s, i);
}

t_variable	*create_var(char *s)
{
	t_variable	*node;

	node = malloc(sizeof(t_variable));
	if (!node)
		return (NULL);
	split_variable(node, s);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	create_double_env(t_variable *head)
{
	t_variable	*tmp;
	t_variable	*prev;

	prev = NULL;
	tmp = head;
	while (tmp != NULL)
	{
		tmp->prev = prev;
		prev = tmp;
		tmp = tmp->next;
	}
}

t_variable	*init_env(char **env)
{
	t_variable	*head;
	t_variable	*tmp;

	if (!env || !*env)
	{
		ft_putstr_fd("lol\n", 2);
		return (NULL);
	}
	tmp = create_var(*env);
	head = tmp;
	env++;
	while (*env)
	{
		tmp->next = create_var(*env);
		tmp = tmp->next;
		env++;
	}
	tmp->next = NULL;
	create_double_env(head);
	return (head);
}
