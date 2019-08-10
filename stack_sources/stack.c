/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:16:47 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 15:16:48 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack			*new_node(int num)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->num = num;
	new->next = 0;
	return (new);
}

void			free_stack(t_stack **stack)
{
	t_stack		*cur;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	*stack = 0;
}

int				get_len(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		++len;
		stack = stack->next;
	}
	return (len);
}

t_stack			*find_last(t_stack *stack)
{
	t_stack		*cur;

	if (!stack)
		return (0);
	cur = stack;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

t_stack			*take_last(t_stack **stack)
{
	t_stack		*cur;
	t_stack		*prev;

	if (!stack || !*stack)
		return (0);
	if ((*stack)->next == 0)
	{
		cur = *stack;
		*stack = 0;
		return (cur);
	}
	prev = *stack;
	cur = *stack;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = 0;
	return (cur);
}

void			show_both(FILE *p, t_stack *a, t_stack *b)
{
	if (!b && !a)
		return;
	else
	{
		if (a && !b)
		{
			show_both(p, a->next, 0);
			p ? fprintf(p,"%d\t \n", a->num) : printf("%d\t \n", a->num);
		}
		else if (b && !a)
		{
			show_both(p, 0, b->next);
			p ? fprintf(p," \t%d\n", b->num) : printf(" \t%d\n", b->num);
		}
		else if (a && b)
		{
			show_both(p, a->next, b->next);
			p ? fprintf(p,"%d\t%d\n", a->num, b->num) : printf("%d\t%d\n", a->num, b->num);
		}
	}
}

void			show_stack(t_stack *stack)
{
	if (stack == 0)
	{
		printf("Empty\n");
		return;
	}
	if (!stack->next)
	{
		printf("%d\n", stack->num);
		return;
	}
	else
	{
		show_stack(stack->next);
		printf("%d\n", stack->num);
		return;
	}
}