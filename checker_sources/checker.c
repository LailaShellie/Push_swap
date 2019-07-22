/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:42:54 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 19:42:55 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void		exec(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("sa\n", str) == 0)
		swap_a(a);
	else if (ft_strcmp("sb\n", str) == 0)
		swap_b(b);
	else if (ft_strcmp("ss\n", str) == 0)
		swap_all(a, b);
	else if (ft_strcmp("pa\n", str) == 0)
		push_a(a, b);
	else if (ft_strcmp("pb\n", str) == 0)
		push_b(a, b);
	else if (ft_strcmp("ra\n", str) == 0)
		rotate_a(a);
	else if (ft_strcmp("rb\n", str) == 0)
		rotate_b(b);
	else if (ft_strcmp("rr\n", str) == 0)
		rotate_all(a, b);
	else if (ft_strcmp("rra\n", str) == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp("rrb\n", str) == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp("rrr\n", str) == 0)
		reverse_rotate_all(a, b);
}

int			try_solve(t_stack **a, t_command **com)
{
	t_stack			*b;
	t_command		*cur_com;

	cur_com = *com;
	b = 0;
	while (cur_com)
	{
		exec(a, &b, cur_com->str);
		cur_com = cur_com->next;
	}
	show_stack(*a);
	if (!(is_sorted(*a, b)))
		return (0);
	return (1);
}

int			check(t_stack **stack)
{
	char		buf[5];
	t_command	*com;

	com = 0;
	ft_memset(buf, 0, 5);
	while (read(0, buf, 4) > 0) //// gnl!!!!
	{
		if (ft_strcmp("\n", buf) == 0)
			break;
		else
			make_commands(&com, buf);
		ft_memset(buf, 0, 5);
	}
	if (!(check_commands(&com)))
		return (0);
	if (!(try_solve(stack, &com)))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack		*first;
	t_stack		*cur;

	first = 0;
	while (--argc)
	{
		if (!is_number(argv[argc]))
			return (error(&first));
		if (!first)
		{
			first = new_node(ft_atoi(argv[argc]));
			cur = first;
		}
		else
		{
			cur->next = new_node(ft_atoi(argv[argc]));
			cur = cur->next;
		}
	}
	if (!(check_duplicates(first)))
		return (error(&first));
	if (!(check(&first)))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (0);
}