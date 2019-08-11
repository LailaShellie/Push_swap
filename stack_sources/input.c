/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:49:17 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/09 10:49:29 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int				is_number(char *str)
{
	if (!*str)
		return (0);
	if ((*str == '+' || *str == '-') && ft_isdigit(*(str + 1)))
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

int				check_duplicates(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
		}
		++i;
	}
	return (1);
}

t_stack			*make_stack(int num, char **str)
{
	t_stack *first;
	t_stack *cur;

	first = 0;
	cur = 0;
	while (--num >= 0)
	{
		if (!first)
		{
			first = new_node(ft_atoi(str[num]));
			cur = first;
		}
		else if (cur)
		{
			cur->next = new_node(ft_atoi(str[num]));
			cur = cur->next;
		}
	}
	return (first);
}

t_stack			*one_str_input(char *str)
{
	char		**s;
	int			i;
	int			num;
	int			ret;
	t_stack		*stack;

	ret = 1;
	i = ft_count_words(str, ' ');
	num = i;
	s = ft_strsplit(str, ' ');
	while (--i >= 0)
	{
		ret = is_number(s[i]) == 0 ? 0 : ret;
		ret = check_overflow(s[i]) == 0 ? 0 : ret;
	}
	ret = check_duplicates(num, s) == 0 ? 0 : ret;
	if (!ret)
	{
		free_str(num, s);
		return (0);
	}
	stack = make_stack(num, s);
	free_str(num, s);
	return (stack);
}

t_stack			*multi_str_input(int num, char **str)
{
	int			i;
	t_stack		*stack;

	i = num;
	stack = 0;
	while (--i >= 0)
	{
		if (!(is_number(str[i])))
			return (0);
		else if (!(check_overflow(str[i])))
			return (0);
	}
	if (!(check_duplicates(num, str)))
		return (0);
	stack = make_stack(num, str);
	return (stack);
}
