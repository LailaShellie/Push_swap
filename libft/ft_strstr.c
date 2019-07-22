/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:54:34 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/20 16:08:29 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *s1;
	const char *s2;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != 0)
	{
		s1 = needle;
		s2 = haystack;
		while (*haystack == *s1 && *s1 != 0)
		{
			++haystack;
			++s1;
		}
		if (*s1 == 0)
			return ((char *)s2);
		haystack = s2;
		++haystack;
	}
	return (0);
}
