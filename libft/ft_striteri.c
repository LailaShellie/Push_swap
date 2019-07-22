/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:51:36 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 16:19:09 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int len;

	i = 0;
	if (s != 0 && f != 0)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			f(i, &s[i]);
			++i;
		}
	}
}
