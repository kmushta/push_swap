/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:42:03 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:42:04 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"
#include "ft_ops_def.h"

static void	ft_opt_srr(t_ft_stack **a, t_ft_stack **s, int op)
{
	t_ft_stack	*e;
	t_ft_stack	*r;

	e = (*s);
	r = e->prev;
	(*a)->value -= 1;
	e->prev->value = op;
	e->prev->next = e->next;
	e->next->prev = e->prev;
	free(e);
	(*s) = r;
}

static void	ft_del_op(t_ft_stack **a, t_ft_stack **s)
{
	t_ft_stack	*e1;
	t_ft_stack	*e2;
	t_ft_stack	*e;

	e = (*s)->prev->prev;
	if ((*a)->value > 1)
	{
		e1 = (*s);
		e2 = (*s)->prev;
		e1->next->prev = e2->prev;
		e2->prev->next = e1->next;
		free(e1);
		free(e2);
		(*a)->value -= 2;
	}
	*s = e;
}

static void	ft_opt_op(t_ft_stack **s)
{
	t_ft_stack	*it;
	int			t[2];

	it = (*s)->prev;
	while (it != (*s)->next)
	{
		*t = it->value;
		t[1] = it->prev->value;
		if ((*t == FT_SA && t[1] == FT_SB) || (*t == FT_SB && t[1] == FT_SA))
			ft_opt_srr(s, &it, FT_SS);
		else if ((*t == FT_RA && t[1] == FT_RB) ||
			(*t == FT_RB && t[1] == FT_RA))
			ft_opt_srr(s, &it, FT_RR);
		else if ((*t == FT_RRA && t[1] == FT_RRB) ||
			(*t == FT_RRB && t[1] == FT_RRA))
			ft_opt_srr(s, &it, FT_RRR);
		else if ((*t == FT_SA && t[1] == FT_SA) || (*t == FT_SB && t[1] ==
			FT_SB) || (*t == FT_RA && t[1] == FT_RRA) || (*t == FT_RRA && t[1]
			== FT_RA) || (*t == FT_PA && t[1] == FT_PB) || (*t == FT_PB && t[1]
			== FT_PA) || (*t == FT_RB && t[1] == FT_RRB) || (*t == FT_RRB &&
			t[1] == FT_RB) || (*t == FT_RR && t[1] == FT_RRR) || (*t == FT_RRR
			&& t[1] == FT_RR))
			ft_del_op(s, &it);
		it = it->prev;
	}
}

void		ft_optimize(t_ft_stack **s)
{
	int		i;

	i = 0;
	while (i++ < 15)
		if ((*s)->value > 1)
			ft_opt_op(s);
}
