/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:47:35 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/30 14:47:36 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sqrt(int nb)
{
	int xn;
	int b;
	int i;

	i = 1;
	b = nb;
	xn = 2;
	if (nb <= 0)
		return (0);
	while (i < 25)
	{
		b = nb / xn;
		xn = (xn + b) / 2;
		i++;
	}
	return (xn);
}

int			ft_is_prime(int nb)
{
	int i;
	int last;

	last = sqrt(nb);
	i = 2;
	while (i <= last)
	{
		if (!(nb % i))
			return (0);
		++i;
	}
	return (1);
}
