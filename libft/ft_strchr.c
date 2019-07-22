/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:50:11 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 16:54:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	sym;
	int		i;

	i = 0;
	sym = c;
	while (s[i])
	{
		if (s[i] == sym)
			return ((char *)(&s[i]));
		++i;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (0);
}
