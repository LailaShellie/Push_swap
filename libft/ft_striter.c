/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:47:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 22:29:09 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t len;
	size_t i;

	len = 0;
	i = 0;
	if (s != 0 && f != 0)
	{
		len = ft_strlen(s);
		while (s[i] != 0)
		{
			f(s + i);
			++i;
		}
	}
}
