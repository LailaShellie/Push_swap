/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:42:58 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 19:43:01 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H
# define _CHECKER_H

# include "../libft/libft.h"
# include "../stack_sources/stack.h"

typedef struct			s_command
{
	char				*str;
	struct s_command	*next;
}						t_command;

int						is_number(char *str);
int						check_duplicates(t_stack *lst);
int						error(t_stack **lst);
int						error_commands(t_command **lst);
int						check_commands(t_command **lst);
void					make_commands(t_command **lst, char *str);
void					free_commands(t_command **lst);

#endif
