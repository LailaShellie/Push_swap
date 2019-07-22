/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:38:04 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/19 19:17:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

static	char		*ft_static(const char *haystack,
		const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		prev_len;

	i = -1;
	while (haystack[++i] != 0 && len > 0)
	{
		k = i;
		j = 0;
		prev_len = len;
		while (haystack[i] == needle[j] && needle[j] != 0 && len != 0)
		{
			i++;
			j++;
			len--;
		}
		if (needle[j] == 0)
			return ((char *)&haystack[k]);
		i = k;
		len = prev_len - 1;
		if (haystack[i] == 0)
			return (0);
	}
	return (0);
}

char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	if (*needle == 0)
		return ((char *)haystack);
	return (ft_static(haystack, needle, len));
}
