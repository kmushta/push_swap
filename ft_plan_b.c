/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plan_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:42:55 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:42:56 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_stack.h"
#include "ft_ops_def.h"

int		ft_plan_b(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	int			med;
	int			q;
	int			s;

	med = ft_get_median(a, (*a)->value);
	q = (*a)->value;
	s = q;
	while (q--)
	{
		if ((*a)->next->value >= med && s % 2)
			ft_ra(a, b, op, 0);
		else if ((*a)->next->value > med)
			ft_ra(a, b, op, 0);
		else
			ft_pb(a, b, op, 0);
	}
	ft_calculate_a(a, b, op, -1);
	ft_calculate_b(a, b, op, -1);
	while ((*b)->value)
		ft_pa(a, b, op, 0);
	return (1);
}
