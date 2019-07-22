/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:04:41 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 20:36:23 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_revstr(char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			c;

	i = 0;
	j = 0;
	while (s[j] != 0)
		++j;
	--j;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		--j;
		++i;
	}
	return (s);
}

static int		ft_count(int n)
{
	int len;
	int nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		++len;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long int	nbr;
	long int	a;
	char		*str;

	nbr = n;
	a = 0;
	if (!(str = (char *)ft_memalloc(sizeof(*str) * (ft_count(n) + 1))))
		return (0);
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		str[a++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[a] = '-';
	++a;
	str[a] = 0;
	return (ft_revstr(str));
}
