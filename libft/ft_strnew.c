/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:16:54 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 20:15:56 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = 0;
	if (size + 1 == 0)
		return (0);
	if (!(str = (char *)ft_memalloc(sizeof(*str) * (size + 1))))
		return (0);
	return (str);
}
