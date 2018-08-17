/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:38:51 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:38:53 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_sort_utils.h"
#include "ft_ops_def.h"

static int	ft_sort_a(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int size)
{
	if (!size)
		return (ft_issorted_a(s));
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_SA))
	{
		ft_sa(s, b, op, 0);
		if (ft_sort_a(s, b, op, size - 1))
			return (1);
		ft_sa(s, b, op, 0);
	}
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_RRA))
	{
		ft_ra(s, b, op, 0);
		if (ft_sort_a(s, b, op, size - 1))
			return (1);
		ft_rra(s, b, op, 0);
	}
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_RA))
	{
		ft_rra(s, b, op, 0);
		if (ft_sort_a(s, b, op, size - 1))
			return (1);
		ft_ra(s, b, op, 0);
	}
	return (0);
}

static int	ft_sort_b(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int size)
{
	if (!size)
		return (ft_issorted_b(s));
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_SB))
	{
		ft_sb(b, s, op, 0);
		if (ft_sort_b(s, b, op, size - 1))
			return (1);
		ft_sb(b, s, op, 0);
	}
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_RRB))
	{
		ft_rb(b, s, op, 0);
		if (ft_sort_b(s, b, op, size - 1))
			return (1);
		ft_rrb(b, s, op, 0);
	}
	if (!(*op)->value || ((*op)->value && (*op)->next->value != FT_RB))
	{
		ft_rrb(b, s, op, 0);
		if (ft_sort_b(s, b, op, size - 1))
			return (1);
		ft_rb(b, s, op, 0);
	}
	return (0);
}

int			ft_calculate_a(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int max)
{
	unsigned int	size;

	size = 0;
	while (size <= max)
	{
		if (ft_sort_a(s, b, op, size))
			return (1);
		size++;
	}
	return (0);
}

int			ft_calculate_b(t_ft_stack **s, t_ft_stack **b,
	t_ft_stack **op, unsigned int max)
{
	unsigned int	size;

	size = 0;
	while (size <= max)
	{
		if (ft_sort_b(b, s, op, size))
			return (1);
		size++;
	}
	return (0);
}
