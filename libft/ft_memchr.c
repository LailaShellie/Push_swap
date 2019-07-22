/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:10:12 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/16 18:18:04 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ss;
	unsigned char cc;

	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n--)
	{
		if (*ss == cc)
			return (ss);
		++ss;
	}
	return (0);
}
