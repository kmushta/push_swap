/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:41:10 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:41:12 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sort_int_tab.h"
#include "ft_stack.h"

static int	ft_median(int *arr, int size)
{
	ft_sort_int_tab(arr, 0, --size);
	return (*(arr + size / 2));
}

int			ft_get_median(t_ft_stack **s, int size)
{
	t_ft_stack	*temp;
	int			*tab;
	int			i;

	tab = (int *)malloc(sizeof(int) * size);
	temp = (*s)->next;
	i = 0;
	while (i < size)
	{
		*(tab + i++) = temp->value;
		temp = temp->next;
	}
	i = ft_median(tab, size);
	free(tab);
	return (i);
}
