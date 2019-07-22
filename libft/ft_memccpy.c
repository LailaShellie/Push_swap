/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:10:09 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 20:26:44 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ddst;
	char	*ssrc;
	char	cc;

	cc = (char)c;
	ddst = (char *)dst;
	ssrc = (char *)src;
	while (n > 0)
	{
		*ddst = *ssrc;
		if (*ssrc == cc)
		{
			++ddst;
			return (ddst);
		}
		++ddst;
		++ssrc;
		--n;
	}
	return (0);
}
