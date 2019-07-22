/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:10:32 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/17 16:17:57 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		++i;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = 0;
	while (j < i)
	{
		str[j] = s1[j];
		++j;
	}
	return (str);
}
