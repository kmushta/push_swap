/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:47:31 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:47:32 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"

t_ft_stack	*new_ft_stack(int value)
{
	t_ft_stack	*new;

	if (!(new = (t_ft_stack *)malloc(sizeof(t_ft_stack))))
		return (0);
	new->value = value;
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_ft_stack	*create_ft_stack(void)
{
	t_ft_stack	*new;

	if (!(new = (t_ft_stack *)malloc(sizeof(t_ft_stack))))
		return (0);
	new->value = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

void		ft_delete_stack(t_ft_stack **s)
{
	while ((*s)->value)
		ft_stack_pop(s);
	free(*s);
	*s = 0;
}

t_ft_stack	*clone_ft_stack(t_ft_stack **s)
{
	t_ft_stack	*new;
	t_ft_stack	*e;

	new = create_ft_stack();
	if (!(*s)->value)
		return (new);
	e = (*s)->next;
	while (e != *s)
	{
		ft_stack_push_back(&new, e->value);
		e = e->next;
	}
	return (new);
}
