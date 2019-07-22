/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:12:11 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/19 20:52:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (alst && del)
	{
		list = *alst;
		del(list->content, list->content_size);
		list->content = 0;
		if (list->next == 0)
		{
			free(*alst);
			*alst = 0;
		}
		else
		{
			ft_lstdel(&list->next, del);
			free(*alst);
			*alst = 0;
		}
	}
}
