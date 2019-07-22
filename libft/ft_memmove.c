/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:07:24 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 15:16:20 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (s > d)
	{
		while (len != i)
		{
			d[i] = s[i];
			++i;
		}
	}
	else if (s < d)
	{
		while (len-- != 0)
			d[len] = s[len];
	}
	return (dst);
}
