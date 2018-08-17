/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:43:43 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:43:44 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops_def.h"
#include "ft_debug.h"

void	ft_ra(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_shift(a);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_RRA)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_RA);
	}
	if (ft_v(0))
		ft_print_s(a, b, "ra");
}

void	ft_rb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_shift(b);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_RRB)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_RB);
	}
	if (ft_v(0))
		ft_print_s(a, b, "rb");
}

void	ft_rra(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_unshift(a);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_RA)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_RRA);
	}
	if (ft_v(0))
		ft_print_s(a, b, "rra");
}

void	ft_rrb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_unshift(b);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_RB)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_RRB);
	}
	if (ft_v(0))
		ft_print_s(a, b, "rrb");
}
