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

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
int					swap_a(t_stack **a);
int					push_a(t_stack **a, t_stack **b);
int					rotate_a(t_stack **a);
int					reverse_rotate_a(t_stack **a);
int					swap_b(t_stack **b);
int					push_b(t_stack **a, t_stack **b);
int					rotate_b(t_stack **b);
int					reverse_rotate_b(t_stack **b);
int					swap_all(t_stack **a, t_stack **b);
int 				reverse_rotate_all(t_stack **a, t_stack **b);
int 				rotate_all(t_stack **a, t_stack **b);

#endif
