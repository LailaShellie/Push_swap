/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:09:08 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/20 16:08:18 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long int	sign;
	long int	nbr;
	long int	prev;

	nbr = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '+' ? 1 : -1);
	if (*str > '9' || *str < '0')
		return (0);
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		prev = nbr;
		nbr = nbr * 10 + (*str - 48);
		str++;
		if (prev > nbr)
			return (sign == -1 ? 0 : -1);
	}
	return (nbr * sign);
}
