/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:50:54 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:50:55 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"

# define FT_MIN_OPS 6
# define FT_MAX_DIF 15
# define MAX_UNSORTED 2

int			ft_error(void);
int			ft_usage(char *s);
int			ft_print_op(int value);
t_ft_stack	**ft_gs(int mode, int n, t_ft_stack *s);
int			ft_get_median(t_ft_stack **s, int size);
void		ft_optimize(t_ft_stack **s);
void		ft_sort_call(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op);
int			ft_plan_b(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op);
void		ft_rrot_a(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int i);
void		ft_rrot_b(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int i);
void		ft_reverse(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op);
int			ft_calculate_a(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int max);
int			ft_calculate_b(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int max);

#endif
