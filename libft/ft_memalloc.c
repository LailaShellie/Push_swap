/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:52:40 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 13:29:26 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	str = 0;
	if (size == 0)
		return (0);
	if (!(str = (void *)malloc(size)))
		return (str);
	ft_bzero(str, size);
	return (str);
}
