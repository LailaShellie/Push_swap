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

#include "stack.h"

int			is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->num < a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int			check_overflow(char *str)
{
	t_num	*num;
	t_num	*limit;
	int 	res;

	if (*str == '-')
	{
		num = make_num(++str);
		limit = make_num("2147483648");
		res = compare_nums(num, limit);
	}
	else
	{
		num = make_num(str);
		limit = make_num("2147483647");
		res = compare_nums(num, limit);
	}
	free_num(num);
	free_num(limit);
	if (res == 1)
		return (0);
	return (1);
}
