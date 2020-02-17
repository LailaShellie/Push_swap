/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:53:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/05 12:53:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median(t_stack *a)
{
	int	len;
	int	*mas;
	int ret;

	len = get_len(a);
	if (!(mas = (int *)ft_memalloc(sizeof(int) * len)))
		return (0);
	copy_mas(mas, a);
	bubble_sort(mas, len);
	ret = mas[(len - 1) >> 1];
	free(mas);
//	printf("%d\n", ret);
	return (ret);
}

void		push_to_b(t_stack **a, t_stack **b)
{
	int			len;
	int 		i;
	int 		median;

	len = get_len(*a);
	if (len == 1)
		return ;
	i = len;
	get_median(*a);
	while (i >= len / 2)
	{
		if (find_last(*a)->num >= median)
		{
			push_b(a, b, PRINT);
			--i;
		}
		else
			reverse_rotate_a(a, PRINT);
	}
	push_to_b(a, b);
//	solve_three(a, b);
}

void		set_turns(t_stack *a, t_stack *b, t_turns *turns)
{
	t_stack		*cur;
	int			len;

	len = get_len(b);
	cur = b;
	while (cur)
	{
		calculate_turns(a, cur, turns, len);
		cur = cur->next;
	}
}

int			solve_hundred(t_stack **a, t_stack **b)
{
	t_turns		turns;

	push_to_b(a, b);
	while (*b)
	{
		turns.sum = -1;
		set_turns(*a, *b, &turns);
		execute(a, b, &turns);
	}
	if (!is_sorted(*a, *b))
		remove_border(a);
	return (1);
}
