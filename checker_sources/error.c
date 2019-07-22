/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:00:37 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/22 12:00:38 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		error(t_stack **lst)
{
	if (lst && *lst)
		free_stack(lst);
	ft_putstr("Error\n");
	return (0);
}

int		error_commands(t_command **lst)
{
	if (lst && *lst)
		free_commands(lst);
	ft_putstr("Error\n");
	return (0);
}