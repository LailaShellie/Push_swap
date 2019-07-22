/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:33:53 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 19:17:58 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	end;

	i = (unsigned int)len;
	if (s == 0)
		return (0);
	if (!(str = (char *)ft_memalloc(sizeof(*s) * (len + 1))))
		return (0);
	end = start + i;
	i = 0;
	while (start < end)
	{
		str[i++] = s[start++];
	}
	str[i] = 0;
	return (str);
}
