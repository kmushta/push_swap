/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:26:14 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 14:26:16 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"
#include "ft_ops_def.h"
#include "ft_sort_utils.h"
#include "ft_debug.h"

void		ft_app_op(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	int		q;

	q = ft_stack_pop(op);
	if (q == FT_SA || q == FT_SS)
		ft_sa(a, b, op, 1);
	if (q == FT_SB || q == FT_SS)
		ft_sb(a, b, op, 1);
	if (q == FT_PA)
		ft_pa(a, b, op, 1);
	if (q == FT_PB)
		ft_pb(a, b, op, 1);
	if (q == FT_RA || q == FT_RR)
		ft_ra(a, b, op, 1);
	if (q == FT_RB || q == FT_RR)
		ft_rb(a, b, op, 1);
	if (q == FT_RRA || q == FT_RRR)
		ft_rra(a, b, op, 1);
	if (q == FT_RRB || q == FT_RRR)
		ft_rrb(a, b, op, 1);
}

int			ft_app(t_ft_stack **s, t_ft_stack **op)
{
	t_ft_stack	*e;
	t_ft_stack	*b;
	int			q;

	q = (*op)->value;
	e = (*op)->next;
	b = create_ft_stack();
	if (ft_v(0))
		ft_print_s(s, &b, 0);
	while (q--)
		ft_app_op(s, &b, op);
	free(*op);
	q = b->value;
	free(b);
	if (q)
		return (0);
	return (ft_issorted_a(s));
}
