/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:09:37 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 20:42:35 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	i = 0;
	start = 0;
	if (s == 0)
		return (0);
	end = ft_strlen(s);
	while (s[start] != 0 && (s[start] == ' ' || s[start] == '\t'
				|| s[start] == '\n'))
		start++;
	while (end != start && (s[end] == ' '
				|| s[end] == '\t' || s[end] == '\n' || s[end] == 0))
		end--;
	i = end - start;
	if (!(str = (char *)malloc(sizeof(*s) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] != 0 && start <= end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
