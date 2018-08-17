/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:50:33 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:50:34 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops_def.h"
#include "libft_funcs.h"
#include "push_swap.h"
#include "ft_validate.h"
#include "ft_debug.h"
#include <stdlib.h>

void		ft_printr(t_ft_stack **s)
{
	int		q;

	q = (*s)->value;
	while (q--)
		ft_print_op(ft_stack_pop_back(s));
}

t_ft_stack	*ft_read_s(char **av)
{
	t_ft_stack *s;

	if (!av)
		return (0);
	s = create_ft_stack();
	while (*av)
	{
		ft_stack_push_back(&s, ft_atoi(*av));
		av++;
	}
	return (s);
}

int			ft_calculate(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op)
{
	*op = create_ft_stack();
	if (ft_v(0))
		ft_print_s(a, b, 0);
	ft_reverse(a, b, op);
	if (ft_calculate_a(a, b, op, FT_MAX_DIF))
		return (1);
	if ((*a)->value <= 2 * FT_MIN_OPS)
	{
		ft_plan_b(a, b, op);
		return (1);
	}
	ft_gs(1, 1, create_ft_stack());
	ft_gs(1, 2, create_ft_stack());
	ft_stack_push(ft_gs(0, 1, 0), (*a)->value);
	ft_sort_call(a, b, op);
	ft_delete_stack(ft_gs(0, 1, 0));
	ft_delete_stack(ft_gs(0, 2, 0));
	return (1);
}

static int	ft_helper(t_ft_stack **s, t_ft_stack **op)
{
	t_ft_stack	*b;

	b = create_ft_stack();
	ft_calculate(s, &b, op);
	if (ft_v(0))
		return (0);
	ft_optimize(op);
	ft_printr(op);
	ft_delete_stack(op);
	ft_delete_stack(s);
	ft_delete_stack(&b);
	return (0);
}

int			main(int ac, char **argv)
{
	t_ft_stack	*s;
	t_ft_stack	*op;
	char		**av;

	if (ac-- < 2)
		return (0);
	av = argv + 1;
	if (ft_strcmp(*av, "-v"))
	{
		ft_v(1);
		av++;
		ac--;
	}
	if (ac == 1)
		if (!(av = ft_strsplit(*av, ' ', &ac)))
			return (ft_error());
	if (!ft_check_list(ac, av))
		return (ft_error());
	if (!ft_check_dups((s = ft_read_s(av))))
		return (ft_error());
	return (ft_helper(&s, &op));
}
