/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:44:56 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:44:57 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_issorted_a(t_ft_stack **s)
{
	t_ft_stack	*temp;
	int			i;

	if (!s && !*s)
		return (0);
	if ((*s)->value < 2)
		return (1);
	temp = (*s)->next;
	i = (*s)->value;
	while (--i)
	{
		if (temp->next->value < temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		ft_issorted_b(t_ft_stack **s)
{
	t_ft_stack	*temp;
	int			i;

	if (!s && !*s)
		return (0);
	if ((*s)->value < 2)
		return (1);
	temp = (*s)->prev;
	i = (*s)->value;
	while (--i)
	{
		if (temp->prev->value < temp->value)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int		ft_sort_entropy(t_ft_stack **s, int i)
{
	t_ft_stack	*temp;
	int			q;

	if (!s && !*s)
		return (0);
	if ((*s)->value < 2)
		return (0);
	temp = (*s)->next;
	if (i <= 0)
		i = (*s)->value;
	q = 0;
	while (--i)
	{
		if (temp->next->value < temp->value)
			q++;
		temp = temp->next;
	}
	return (q);
}
