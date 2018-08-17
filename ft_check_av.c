/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:39:21 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:39:23 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static int	ft_is_int(char *s)
{
	unsigned long long int	q;
	char					sign;
	char					f;

	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	sign = 0;
	if (*s == '-')
	{
		sign = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	q = 0;
	f = 0;
	while (*s >= '0' && *s <= '9')
	{
		q = q * 10 + *s++ - 48;
		if ((f = 1) && (((q > 2147483647) && !sign) || q > 2147483648))
			return (0);
	}
	if (!*s && f)
		return (1);
	return (0);
}

static int	ft_check_symbols(char *s)
{
	while (*s)
	{
		if (!(*s > 8 && *s < 14) && *s != 32
			&& *s != '+' && *s != '-' &&
			!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

static int	ft_check(char *s)
{
	if (!ft_check_symbols(s) || !ft_is_int(s))
		return (0);
	return (1);
}

int			ft_check_list(int ac, char **av)
{
	if (!*av)
		return (0);
	while (ac--)
		if (!ft_check(*av++))
			return (0);
	return (1);
}

int			ft_check_dups(t_ft_stack *s)
{
	t_ft_stack	*e;
	t_ft_stack	*it;

	if (!s || s->value < 2)
		return (1);
	e = s->next;
	while (e != s->prev)
	{
		it = e->next;
		while (it != s)
		{
			if (e->value == it->value)
				return (0);
			it = it->next;
		}
		e = e->next;
	}
	return (1);
}
