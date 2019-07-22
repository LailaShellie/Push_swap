/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:13:32 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/30 14:13:33 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		*ft_zfunc(const char *str)
{
	unsigned int	*z;
	unsigned int	i;
	unsigned int	j;

	if (!(z = (unsigned int *)ft_memalloc(sizeof(int) * ft_strlen(str))))
		return (0);
	z[0] = 0;
	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[i] != str[j] && j == 0)
			z[i] = 0;
		else if (str[i] != str[j] && j != 0)
			j = z[j - 1];
		if (str[i] == str[j])
			z[i] = ++j;
		++i;
	}
	return (z);
}
