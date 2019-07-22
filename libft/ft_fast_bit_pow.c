/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_bin_pow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:56:13 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/31 12:56:17 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_fast_bit_pow(unsigned long int a,
		unsigned long int b)
{
	unsigned long int	i;
	unsigned long int	res;

	res = 1;
	i = 31;
	while (i)
	{
		if (b & 1 << i)
			res *= a;
		res *= res;
		--i;
	}
	if (b & 1)
		res *= a;
	return (res);
}
