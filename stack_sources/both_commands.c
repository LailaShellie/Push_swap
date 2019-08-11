/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:12:42 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 17:12:43 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			swap_all(t_stack **a, t_stack **b, int flag)
{
	if (flag == PRINT)
		ft_putstr("ss\n");
	return (swap_a(a, NOPRINT) + swap_b(b, flag));
}

int			rotate_all(t_stack **a, t_stack **b, int flag)
{
	if (flag == PRINT)
		ft_putstr("rr\n");
	return (rotate_a(a, NOPRINT) + rotate_b(b, NOPRINT));
}

int			reverse_rotate_all(t_stack **a, t_stack **b, int flag)
{
	if (flag == PRINT)
		ft_putstr("rrr\n");
	return (reverse_rotate_a(a, NOPRINT) + reverse_rotate_b(b, NOPRINT));
}
