/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:38:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 14:34:20 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strclr(char *s)
{
	size_t len;
	size_t i;

	if (s != 0)
	{
		i = 0;
		len = 0;
		len = ft_strlen(s);
		i = 0;
		if (len != 0)
		{
			while (i < len)
				s[i++] = 0;
		}
	}
}
