/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_kmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:23:00 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/28 18:23:01 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr_kmp(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	*z;
	char			*p;

	z = ft_zfunc(needle);
	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0)
	{
		p = (char *)(&haystack[i - j]);
		while (haystack[i] == needle[j] && needle[j] != 0)
		{
			++i;
			++j;
		}
		if (needle[j] == 0)
			return (p);
		j == 0 ? ++i : (j = z[j - 1]);
	}
	return (0);
}
