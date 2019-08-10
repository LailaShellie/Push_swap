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

void	push_to_b(t_stack **a, t_stack **b)
{
	int len;

	len = get_len(*a);
	while (len > 3)
	{
		push_b(a, b, PRINT);
		--len;
	}
	solve_three(a, b);
//	show_both(*a, *b);
//	printf("-------\n");
}

void	set_turns(t_stack *a, t_stack *b, t_turns *turns)
{
	t_stack *cur;
	int 	len;

	len = get_len(b);
	cur = b;
	while (cur)
	{
		calculate_turns(a, cur, turns, len);
		cur = cur->next;
	}
//	printf("TURN\n%d - num\n%d - exec_b\n%d - exec_a\n%d - sum\n--------\n",
//		   turns->num, turns->exec_b, turns->exec_a, turns->sum);
}

int 	solve_hundred(t_stack **a, t_stack **b)
{
	t_turns		turns;
//	FILE *p;

//	p = fopen ("test.txt","w");
	push_to_b(a, b);
	while (*b)
	{
		turns.sum = -1;
		set_turns(*a, *b, &turns);
//		fprintf(p, "TURN\n%d - num\n%d - exec_b\n%d - exec_a\n%d - sum\n--------\n",
//			   turns.num, turns.exec_b, turns.exec_a, turns.sum);
		execute(a, b, &turns);
//		show_both(p, *a, *b);
	}
	remove_border(a);
//	show_both(0, *a, *b);
	return (1);
}