/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:57:26 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/19 20:53:21 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *cur;

	if (f)
	{
		cur = lst;
		if (cur != 0)
		{
			f(cur);
			ft_lstiter(cur->next, f);
		}
	}
}
