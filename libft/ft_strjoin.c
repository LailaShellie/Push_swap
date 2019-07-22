/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:11:13 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 16:25:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 1;
	if (!(str = (char *)ft_memalloc(sizeof(str) * len)))
		return (0);
	while (i < len1)
	{
		str[i] = *s1;
		++i;
		++s1;
	}
	while (i < len)
		str[i++] = *s2++;
	str[len] = 0;
	return (str);
}
