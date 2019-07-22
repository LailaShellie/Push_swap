/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:31:33 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/19 20:52:15 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (0);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (void *)malloc(content_size)))
		{
			free(new);
			return (0);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = 0;
	return (new);
}
