/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:40:44 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:40:46 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_funcs.h"
#include "libftprintf.h"

int		ft_error(void)
{
	ft_putendl_fd(2, "Error");
	return (0);
}

int		ft_usage(char *s)
{
	ft_printf("Usage: %s [flag \"-v\" to verbose (optional)] [int array]\n", s);
	ft_printf("Then use those commands to sort the stack:\n");
	ft_printf("sa: swap a - swap the first 2 elements at the top of stack a\n");
	ft_printf("sb: swap b - swap the first 2 elements at the top of stack b\n");
	ft_printf("ss: sa and sb at the same time.\n");
	ft_printf("pa: push a - take the first element at the top of b ");
	ft_printf("and put it at the top of a\n");
	ft_printf("pb: push b - take the first element at the top of a ");
	ft_printf("and put it at the top of b\n");
	ft_printf("ra: rotate a - shift up all elements of stack a by 1\n");
	ft_printf("rb: rotate b - shift up all elements of stack b by 1\n");
	ft_printf("rr: ra and rb at the same time\n");
	ft_printf("rra: reverse rotate a - shift down all elements of stack a ");
	ft_printf("by 1\n");
	ft_printf("rrb: reverse rotate b - shift down all elements of stack b ");
	ft_printf("by 1\n");
	ft_printf("rrr: rra and rrb at the same time\n");
	return (0);
}
