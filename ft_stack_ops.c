/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:46:39 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:46:40 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_swap(t_ft_stack **s)
{
	int		a;
	int		b;

	if (!s || !*s)
		return (0);
	if ((*s)->value < 2)
		return (0);
	a = ft_stack_pop(s);
	b = ft_stack_pop(s);
	ft_stack_push(s, a);
	ft_stack_push(s, b);
	return (1);
}

int		ft_shift(t_ft_stack **s)
{
	if (!s || !*s)
		return (0);
	if ((*s)->value < 2)
		return (0);
	ft_stack_push_back(s, ft_stack_pop(s));
	return (1);
}

int		ft_unshift(t_ft_stack **s)
{
	if (!s || !*s)
		return (0);
	if ((*s)->value < 2)
		return (0);
	ft_stack_push(s, ft_stack_pop_back(s));
	return (1);
}

int		ft_push(t_ft_stack **a, t_ft_stack **b)
{
	if (!a || !b || !*a || !*b)
		return (0);
	if (!(*b)->value)
		return (0);
	ft_stack_push(a, ft_stack_pop(b));
	return (1);
}
