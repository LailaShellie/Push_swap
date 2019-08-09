/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:07:35 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/09 11:12:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_count_words(const char *s, int c)
{
	int end_of_line;
	int end_of_word;

	while (*s)
	{
		if (*s == 0)
			return (0);
		end_of_line = (*s != c && *(s + 1) == 0);
		end_of_word = (*s != c && *(s + 1) == c);
		if (end_of_line || end_of_word)
			return (1 + ft_count_words(++s, c));
		++s;
	}
	return (0);
}
