/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:42:29 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:42:31 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops_def.h"
#include "ft_debug.h"

void	ft_pa(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_push(a, b);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_PB)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_PA);
	}
	if (ft_v(0))
		ft_print_s(a, b, "pa");
}

void	ft_pb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode)
{
	ft_push(b, a);
	if (!mode)
	{
		if ((*op)->value && (*op)->next->value == FT_PA)
			ft_stack_pop(op);
		else
			ft_stack_push(op, FT_PB);
	}
	if (ft_v(0))
		ft_print_s(a, b, "pb");
}
