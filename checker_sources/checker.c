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

void		exec(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp("sa", str) == 0)
		swap_a(a);
	else if (ft_strcmp("sb", str) == 0)
		swap_b(b);
	else if (ft_strcmp("ss", str) == 0)
		swap_all(a, b);
	else if (ft_strcmp("pa", str) == 0)
		push_a(a, b);
	else if (ft_strcmp("pb", str) == 0)
		push_b(a, b);
	else if (ft_strcmp("ra", str) == 0)
		rotate_a(a);
	else if (ft_strcmp("rb", str) == 0)
		rotate_b(b);
	else if (ft_strcmp("rr", str) == 0)
		rotate_all(a, b);
	else if (ft_strcmp("rra", str) == 0)
		reverse_rotate_a(a);
	else if (ft_strcmp("rrb", str) == 0)
		reverse_rotate_b(b);
	else if (ft_strcmp("rrr", str) == 0)
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
	if (!(is_sorted(*a, b)))
		return (0);
	return (1);
}

int			check(t_stack **stack)
{
	char		*str;
	t_command	*com;

	com = 0;
    while (get_next_line(1, &str))
    {
		if (ft_strcmp("", str) == 0)
			break;
		if (!(check_commands(str)))
			return (error_commands(&com));
		else
			make_commands(&com, str);
		free(str);
	}
	if (!(try_solve(stack, &com)))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack		*first;
	t_stack		*cur;

	first = 0;
	if (argc == 1)
		return (0);
	if (!(check_input(argc, argv)))
		return (error(0));
	while (--argc)
	{
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
	check(&first);
	free_stack(&first);
	return (0);
}