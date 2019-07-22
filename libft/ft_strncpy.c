/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:11:26 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 19:52:25 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;
	size_t lenght;

	lenght = len;
	i = 0;
	j = 0;
	while (i < lenght && src[j] != '\0')
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	while (i < lenght && src[j] == '\0')
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
