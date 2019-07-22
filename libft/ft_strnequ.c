/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:01:34 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/18 15:59:18 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (n == 0)
		return (1);
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (0);
		--n;
		if (n == 0)
			return (1);
		++i;
	}
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}
