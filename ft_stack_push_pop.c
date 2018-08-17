/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:47:09 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:47:10 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"

static void	ft_del_stack(t_ft_stack **s)
{
	if (s && *s)
	{
		(*s)->next->prev = (*s)->prev;
		(*s)->prev->next = (*s)->next;
		free(*s);
	}
}

void		ft_stack_push(t_ft_stack **s, int value)
{
	t_ft_stack	*new;

	if (s && *s)
	{
		if ((new = new_ft_stack(value)))
		{
			(*s)->next->prev = new;
			new->next = (*s)->next;
			new->prev = *s;
			(*s)->next = new;
			(*s)->value += 1;
		}
	}
}

void		ft_stack_push_back(t_ft_stack **s, int value)
{
	t_ft_stack	*new;

	if (s && *s)
	{
		if ((new = new_ft_stack(value)))
		{
			(*s)->prev->next = new;
			new->prev = (*s)->prev;
			new->next = *s;
			(*s)->prev = new;
			(*s)->value += 1;
		}
	}
}

int			ft_stack_pop(t_ft_stack **s)
{
	t_ft_stack	*temp;
	int			value;

	if (s && *s && (*s)->value)
	{
		temp = (*s)->next;
		temp->next->prev = *s;
		(*s)->next = temp->next;
		value = temp->value;
		ft_del_stack(&temp);
		(*s)->value -= 1;
		return (value);
	}
	return (0);
}

int			ft_stack_pop_back(t_ft_stack **s)
{
	t_ft_stack	*temp;
	int			value;

	if (s && *s && (*s)->value)
	{
		temp = (*s)->prev;
		temp->prev->next = *s;
		(*s)->prev = temp->prev;
		value = temp->value;
		ft_del_stack(&temp);
		(*s)->value -= 1;
		return (value);
	}
	return (0);
}
