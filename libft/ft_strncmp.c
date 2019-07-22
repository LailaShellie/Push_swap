/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 20:41:16 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 13:58:57 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] < c2[i])
			return (c1[i] - c2[i]);
		else if (c1[i] > c2[i])
			return (c1[i] - c2[i]);
		else if (c1[i] == '\0' && c2[i] == '\0')
			return (0);
		++i;
	}
	return (0);
}
