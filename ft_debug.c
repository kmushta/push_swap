/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:39:46 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:39:47 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops_def.h"
#include "libft_funcs.h"
#include "libftprintf.h"

int			ft_v(int mode)
{
	static char	verbose;

	if (!mode)
		return (verbose);
	else
	{
		if (verbose)
			verbose = 0;
		else
			verbose = 1;
	}
	return (0);
}

void		ft_print_s(t_ft_stack **a, t_ft_stack **b, const char *op)
{
	t_ft_stack	*e;

	if (op)
		ft_printf("%s\n", op);
	e = (*a)->next;
	ft_printf("(A)>> : ");
	while (e != *a)
	{
		ft_printf(" %d", e->value);
		e = e->next;
	}
	e = (*b)->next;
	ft_printf("\n(B)>> : ");
	while (e != *b)
	{
		ft_printf(" %d", e->value);
		e = e->next;
	}
	ft_printf("\n");
}

t_ft_stack	**ft_gs(int mode, int n, t_ft_stack *s)
{
	static t_ft_stack	*ga;
	static t_ft_stack	*gb;

	if (!mode)
	{
		if (n == 1)
			return (&ga);
		if (n == 2)
			return (&gb);
		return (0);
	}
	else
	{
		if (n == 1)
			ga = s;
		if (n == 2)
			gb = s;
	}
	return (0);
}
