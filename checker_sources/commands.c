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

int				check_commands(t_command **lst)
{
	t_command		*cur;

	if (!*lst)
		return (1);
	cur = *lst;
	while (cur)
	{
		if (ft_strcmp("sa\n", cur->str) && ft_strcmp("sb\n", cur->str) &&
		ft_strcmp("ss\n", cur->str) && ft_strcmp("pa\n", cur->str) &&
		ft_strcmp("pb\n", cur->str) && ft_strcmp("ra\n", cur->str) &&
		ft_strcmp("rb\n", cur->str) && ft_strcmp("rr\n", cur->str) &&
		ft_strcmp("rrb\n", cur->str) && ft_strcmp("rra\n", cur->str) &&
		ft_strcmp("rrr\n", cur->str))
			return (error_commands(lst));
		cur = cur->next;
	}
	return (1);
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
