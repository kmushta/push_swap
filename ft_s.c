/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:44:32 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:44:33 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops_def.h"
#include "ft_debug.h"

void	ft_sa(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_swap(a);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_SA)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_SA);
	}
	if (ft_v(0))
		ft_print_s(a, b, "sa");
}

void	ft_sb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_swap(b);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_SB)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_SB);
	}
	if (ft_v(0))
		ft_print_s(a, b, "sb");
}
