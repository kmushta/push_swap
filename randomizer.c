/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:46:59 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 14:47:00 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "libft_funcs.h"
#include "libftprintf.h"

static int	ft_is_int(char *s)
{
	unsigned long long int	result;

	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	if (*s == '-')
		return (0);
	else if (*s == '+')
		s++;
	result = 0;
	while (*s >= '0' && *s <= '9')
	{
		result = result + *s++ - 48;
		if (result > 32767)
			return (0);
	}
	if (!*s && result)
		return (1);
	return (0);
}

static void	ft_rand_swap(int *tab, int size)
{
	int		i;
	int		r;
	int		temp;

	i = size;
	while (--i > 0)
	{
		r = rand();
		r %= i;
		temp = *(tab + i);
		*(tab + i) = *(tab + r);
		*(tab + r) = temp;
	}
}

int			main(int argc, char **av)
{
	int		size;
	int		*tab;
	int		i;

	if (argc != 2 || !ft_is_int(*(av + 1)))
	{
		ft_printf("Usage: %s [array size (int from 1 to 32767)]\n", *av);
		return (0);
	}
	size = ft_atoi(*(av + 1));
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (write(2, "Error\n", 6) * 0);
	i = -1;
	while (++i < size)
		*(tab + i) = i + 1;
	srand(time(0));
	ft_rand_swap(tab, size);
	ft_printf("%d", *tab);
	i = 0;
	while (++i < size)
		ft_printf(" %d", *(tab + i));
	write(1, "\n", 1);
	free(tab);
	return (0);
}
