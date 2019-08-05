/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:24:55 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/22 13:24:56 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		error_commands(t_command **lst)
{
	if (lst && *lst)
		free_commands(lst);
	ft_putstr("Error\n");
	return (-1);
}

t_command		*new_command(char *str)
{
	t_command		*new;

	if (!(new = (t_command *)malloc(sizeof(t_command))))
		return (0);
	new->str = ft_strdup(str);
	new->next = 0;
	return (new);
}

void			free_commands(t_command **lst)
{
	t_command		*cur;

	if (!lst || !*lst)
		return ;
	cur = *lst;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	*lst = 0;
}

int				check_commands(char *str)
{
	return  (!ft_strcmp("sa", str) || !ft_strcmp("sb", str) ||
		!ft_strcmp("ss", str) || !ft_strcmp("pa", str) ||
		!ft_strcmp("pb", str) || !ft_strcmp("ra", str) ||
		!ft_strcmp("rb", str) || !ft_strcmp("rr", str) ||
		!ft_strcmp("rrb", str) || !ft_strcmp("rra", str) ||
		!ft_strcmp("rrr", str));
}

void			make_commands(t_command **lst, char *str)
{
	t_command		*cur;

	if (!*lst)
	{
		*lst = new_command(str);
		return;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_command(str);
}
