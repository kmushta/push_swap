/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:45:21 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:45:22 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bubble_sort(int *tab, int size)
{
	char	f;
	int		i;
	int		j;
	int		temp;

	f = 1;
	i = size;
	while (f && i--)
	{
		f = 0;
		j = -1;
		while (++j < i)
			if (*(tab + j) > *(tab + j + 1))
			{
				temp = *(tab + j);
				*(tab + j) = *(tab + j + 1);
				*(tab + j + 1) = temp;
				f = 1;
			}
	}
}

static void	ft_merge_sort(int *array, int lo, int mid, int hi)
{
	int		tab[4];
	int		*target;

	*tab = 0;
	*(tab + 1) = lo;
	*(tab + 2) = ++mid;
	*(tab + 3) = hi - lo + 1;
	target = (int *)malloc(sizeof(int) * *(tab + 3));
	while (*(tab + 1) < mid && *(tab + 2) <= hi)
		if (*(array + *(tab + 1)) <= *(array + *(tab + 2)))
			*(target + (*tab)++) = *(array + (*(tab + 1))++);
		else
			*(target + (*tab)++) = *(array + (*(tab + 2))++);
	if (*(tab + 2) > hi)
		while (*(tab + 1) < mid)
			*(target + (*tab)++) = *(array + (*(tab + 1))++);
	else
		while (*(tab + 2) <= hi)
			*(target + (*tab)++) = *(array + (*(tab + 2))++);
	*tab = 0;
	*(tab + 1) = lo;
	while (*tab < *(tab + 3))
		*(array + (*(tab + 1))++) = *(target + (*tab)++);
	free(target);
}

void		ft_sort_int_tab(int *array, int lo, int hi)
{
	int		mid;

	if (hi - lo > 17)
	{
		mid = (lo + hi) >> 1;
		ft_sort_int_tab(array, lo, mid);
		ft_sort_int_tab(array, mid + 1, hi);
		ft_merge_sort(array, lo, mid, hi);
	}
	else if (hi - lo > 1)
		ft_bubble_sort(array + lo, hi - lo + 1);
}
