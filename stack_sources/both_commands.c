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

int			swap_all(t_stack **a, t_stack **b)
{
	return (swap_a(a) + swap_b(b));
}

int			rotate_all(t_stack **a, t_stack **b)
{
	return (rotate_a(a) + rotate_b(b));
}

int 		reverse_rotate_all(t_stack **a, t_stack **b)
{
	return (reverse_rotate_a(a) + reverse_rotate_b(b));
}