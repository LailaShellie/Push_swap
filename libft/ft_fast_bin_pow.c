/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:33:02 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/31 12:33:05 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned long int	ft_fast_bin_pow(unsigned long int a,
		unsigned long int b)
{
	unsigned long int res;

	res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return (res);
}
