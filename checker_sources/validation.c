/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:45:50 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 19:45:51 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			is_number(char *str)
{
	if (!*str)
		return (0);
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

int			check_duplicates(t_stack *lst)
{
	t_stack	*cur;

	if (!lst)
		return (0);
	while (lst->next)
	{
		cur = lst->next;
		while (cur)
		{
			if (cur->num == lst->num)
				return (0);
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (1);
}