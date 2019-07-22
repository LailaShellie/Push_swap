/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:12:21 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/16 22:22:34 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dst_len;
	size_t src_len;
	size_t len;

	dst_len = 0;
	len = size;
	src_len = ft_strlen(src);
	while (dst[dst_len] != 0 && len != 0)
	{
		dst_len++;
		--len;
	}
	len = size - dst_len;
	if (len == 0)
		return (size + src_len);
	i = 0;
	j = dst_len;
	while (src[i] != 0 && len-- > 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = 0;
	return (src_len + dst_len);
}
