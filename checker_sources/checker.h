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

typedef struct          s_num
{
    int                 num;
    struct s_num        *next;
}                       t_num;

int						is_number(char *str);
int						error(t_stack **lst);
int						error_commands(t_command **lst);
int						check_commands(char *str);
void					make_commands(t_command **lst, char *str);
void					free_commands(t_command **lst);
int						compare_nums(t_num *num1, t_num *num2);
t_num       			*make_num(char *str);
void        			free_num(t_num *lst);
int						check_input(int argc, char **argv);
int						is_sorted(t_stack *a, t_stack *b);

#endif
