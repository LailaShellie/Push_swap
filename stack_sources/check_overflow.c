/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:22:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/30 12:22:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int			get_num_len(t_num *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

static t_num		*new_num(char c)
{
	t_num	*new;

	if (!(new = (t_num *)malloc(sizeof(t_num))))
		return (0);
	new->num = c + '0';
	new->next = 0;
	return (new);
}

void				free_num(t_num *lst)
{
	t_num *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_num				*make_num(char *str)
{
	t_num	*cur;
	t_num	*first;

	first = 0;
	while (*str)
	{
		if (first == 0)
		{
			first = new_num(*str);
			cur = first;
		}
		else
		{
			cur->next = new_num(*str);
			cur = cur->next;
		}
		++str;
	}
	return (first);
}

int					compare_nums(t_num *num1, t_num *num2)
{
	if (get_num_len(num1) > get_num_len(num2))
		return (1);
	else if (get_num_len(num1) < get_num_len(num2))
		return (0);
	while (num1 && num2)
	{
		if (num1->num > num2->num)
			return (1);
		num1 = num1->next;
		num2 = num2->next;
	}
	return (0);
}
