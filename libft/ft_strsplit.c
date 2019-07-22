/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:55 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/19 19:58:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_count_words(const char *s, int c)
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

static unsigned int	ft_wrdlen(const char *s, int c)
{
	unsigned int len;

	len = 0;
	if (s != 0)
	{
		while (*s != 0 && *s != c)
		{
			++len;
			++s;
		}
	}
	return (len);
}

static char			**ft_free_str(char **str)
{
	while (*str)
	{
		free(*str);
		++str;
	}
	free(str);
	str = 0;
	return (0);
}

static char			**ft_alloc(char const *s, char c)
{
	unsigned int	wrd_num;
	char			**str;
	unsigned int	wrd_i;
	unsigned int	str_i;
	unsigned int	sym_i;

	wrd_i = 0;
	str_i = 0;
	wrd_num = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(str) * (wrd_num + 1))))
		return (0);
	while (wrd_i < wrd_num)
	{
		while (*(s + str_i) == c)
			++str_i;
		if (!(str[wrd_i] = (char *)malloc(sizeof(str[wrd_i])
						* (ft_wrdlen(s + str_i, c) + 1))))
			return (ft_free_str(str));
		sym_i = 0;
		while (s[str_i] != c && s[str_i] != 0)
			str[wrd_i][sym_i++] = s[str_i++];
		str[wrd_i++][sym_i] = 0;
	}
	str[wrd_i] = 0;
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	if (s == 0)
		return (0);
	return (ft_alloc(s, c));
}
