/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:53:41 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/30 14:53:42 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

# include "../stack_sources/stack.h"
# include "../checker_sources/checker.h"

void	calculate_set_in_a(t_stack *a, t_turns *tmp, int num);
void	calculate_get_in_b(t_stack *b, t_turns *tmp, int len);
void	calculate_turns(t_stack *a, t_stack *b, t_turns *turns, int len);
void	execute(t_stack **a, t_stack **b, t_turns *turns);

int 	solve_three(t_stack **a, t_stack **b);
int 	solve_hundred(t_stack **a, t_stack **b);

#endif
