/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:43:19 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:43:20 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops_def.h"
#include "libft_funcs.h"

int		ft_print_op(int value)
{
	if (value == FT_SA)
		return (ft_putendl_fd(1, "sa"));
	if (value == FT_SB)
		return (ft_putendl_fd(1, "sb"));
	if (value == FT_SS)
		return (ft_putendl_fd(1, "ss"));
	if (value == FT_PA)
		return (ft_putendl_fd(1, "pa"));
	if (value == FT_PB)
		return (ft_putendl_fd(1, "pb"));
	if (value == FT_RA)
		return (ft_putendl_fd(1, "ra"));
	if (value == FT_RB)
		return (ft_putendl_fd(1, "rb"));
	if (value == FT_RR)
		return (ft_putendl_fd(1, "rr"));
	if (value == FT_RRA)
		return (ft_putendl_fd(1, "rra"));
	if (value == FT_RRB)
		return (ft_putendl_fd(1, "rrb"));
	if (value == FT_RRR)
		return (ft_putendl_fd(1, "rrr"));
	return (0);
}
