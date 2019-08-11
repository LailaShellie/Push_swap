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
# define PUSH_SWAP_PUSH_SWAP_H

# include "../stack_sources/stack.h"
# include "../checker_sources/checker.h"

void	calculate_turns(t_stack *a, t_stack *b, t_turns *turns, int len);
int		get_mid(t_stack *stack);
int		calculate_bot(t_stack *a, t_turns *tmp, int len);
int		calculate_top(t_stack *a, t_turns *tmp, int len);
void	calculate_with_borders(t_stack *a, t_turns *tmp, int len);
void	calculate_pos(t_turns *tmp, int pos, int len);
void	execute(t_stack **a, t_stack **b, t_turns *turns);
void	remove_border(t_stack **a);
int		solve_three(t_stack **a, t_stack **b);
int		solve_hundred(t_stack **a, t_stack **b);

#endif
