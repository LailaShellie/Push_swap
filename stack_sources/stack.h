/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:11:27 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/21 15:11:28 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef __STACK_H
# define __STACK_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define PRINT 1
# define NOPRINT 0

typedef struct			s_turns
{
	int					get_in_b;
	int 				set_in_a;
	int 				place;
	int 				doubles;
	int 				sum;
	int					num;
}						t_turns;

typedef struct          s_num
{
	int                 num;
	struct s_num        *next;
}                       t_num;

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void				show_stack(t_stack *stack);
void				show_both(t_stack *a, t_stack *b);

t_stack				*new_node(int num);
void				free_stack(t_stack **stack);
int					get_len(t_stack *stack);
t_stack				*find_last(t_stack *stack);
t_stack				*take_last(t_stack **stack);
int					swap_a(t_stack **a, int flag);
int					push_a(t_stack **a, t_stack **b, int flag);
int					rotate_a(t_stack **a,  int flag);
int					reverse_rotate_a(t_stack **a, int flag);
int					swap_b(t_stack **b,  int flag);
int					push_b(t_stack **a, t_stack **b, int flag);
int					rotate_b(t_stack **b,  int flag);
int					reverse_rotate_b(t_stack **b, int flag);
int					swap_all(t_stack **a, t_stack **b, int flag);
int 				reverse_rotate_all(t_stack **a, t_stack **b, int flag);
int 				rotate_all(t_stack **a, t_stack **b, int flag);

int					check_input(int argc, char **argv);
int					compare_nums(t_num *num1, t_num *num2);
t_num       		*make_num(char *str);
void        		free_num(t_num *lst);
int					is_number(char *str);
int					is_sorted(t_stack *a, t_stack *b);
int					error(t_stack **lst);
t_stack				*one_string(char *str);

#endif
