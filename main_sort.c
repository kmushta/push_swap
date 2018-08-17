/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:49:36 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:49:38 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "push_swap.h"
#include "ft_sort_utils.h"
#include "ft_ops_def.h"

void		ft_swap2(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	if ((*a)->value <= FT_MIN_OPS)
		ft_calculate_a(a, b, op, FT_MAX_DIF);
	else if ((*ft_gs(0, 1, 0))->next->value == 2 &&
		(*a)->next->value > (*a)->next->next->value)
		ft_sa(a, b, op, 0);
}

static int	ft_push_b_a(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	int	t[3];

	while ((*ft_gs(0, 1, 0))->next->value > MAX_UNSORTED && !ft_issorted_a(a) &&
		(*a)->value > FT_MIN_OPS)
	{
		*(t + 2) = ft_get_median(a, (*ft_gs(0, 1, 0))->next->value);
		*(t + 1) = (*ft_gs(0, 1, 0))->next->value;
		*t = 0;
		while ((*(t + 1))--)
			if ((*a)->next->value < *(t + 2) && ((*t)++ + 1))
			{
				ft_pb(a, b, op, 0);
				if (*t == 2 && (*b)->next->value < (*b)->next->next->value)
					ft_sb(a, b, op, 0);
			}
			else
				ft_ra(a, b, op, 0);
		(*ft_gs(0, 1, 0))->next->value -= *t;
		if ((*ft_gs(0, 1, 0))->next->value != (*a)->value)
			ft_rrot_a(a, b, op, (*ft_gs(0, 1, 0))->next->value);
		ft_stack_push(ft_gs(0, 2, 0), *t);
	}
	ft_swap2(a, b, op);
	return (((*ft_gs(0, 1, 0))->next->value = 0));
}

static void	ft_push_a_b(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	int	t[3];

	if (!(*ft_gs(0, 2, 0))->value)
		return ;
	if ((*(t + 1) = (*ft_gs(0, 2, 0))->next->value) <= MAX_UNSORTED ||
		ft_issorted_b(b))
	{
		(*ft_gs(0, 1, 0))->next->value += *(t + 1);
		while ((*(t + 1))--)
			ft_pa(a, b, op, 0);
		ft_stack_pop(ft_gs(0, 2, 0));
		ft_swap2(a, b, op);
		return ;
	}
	*(t + 2) = ft_get_median(b, (*ft_gs(0, 2, 0))->next->value);
	*t = 0;
	while ((*(t + 1))--)
		if ((*b)->next->value >= *(t + 2) && ((*t)++ + 1))
			ft_pa(a, b, op, 0);
		else
			ft_rb(a, b, op, 0);
	if (((*ft_gs(0, 2, 0))->next->value -= *t) != (*b)->value)
		ft_rrot_b(a, b, op, (*ft_gs(0, 2, 0))->next->value);
	(*ft_gs(0, 1, 0))->next->value += *t;
}

void		ft_sort_call(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	while (!ft_issorted_a(a) || (*b)->value)
	{
		ft_push_b_a(a, b, op);
		if ((*b)->value <= FT_MIN_OPS)
			ft_calculate_b(a, b, op, FT_MAX_DIF);
		ft_push_a_b(a, b, op);
	}
}
