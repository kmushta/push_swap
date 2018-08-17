/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:44:06 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:44:08 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"
#include "ft_ops_def.h"
#include "ft_sort_utils.h"

void	ft_rrot_a(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int i)
{
	while (i--)
		ft_rra(a, b, op, 0);
}

void	ft_rrot_b(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int i)
{
	while (i--)
		ft_rrb(a, b, op, 0);
}

void	ft_reverse(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	int		q;

	if (ft_sort_entropy(a, (*a)->value) * 1.185 <= (*a)->value ||
		(*a)->value <= FT_MIN_OPS)
		return ;
	q = (*a)->value - FT_MIN_OPS;
	while (q--)
		ft_pb(a, b, op, 0);
	ft_calculate_a(a, b, op, 15);
	q = (*b)->value;
	while (q--)
	{
		ft_pa(a, b, op, 0);
		ft_ra(a, b, op, 0);
	}
}
