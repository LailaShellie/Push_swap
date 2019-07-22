/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:44:25 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 15:06:21 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ddst;
	unsigned char *ssrc;

	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (ddst == 0 && ssrc == 0)
		return (0);
	while (n--)
	{
		*ddst = *ssrc;
		++ddst;
		++ssrc;
	}
	return (dst);
}
