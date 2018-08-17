/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:40:20 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:40:21 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# include "ft_stack.h"

int			ft_v(int mode);
void		ft_print_s(t_ft_stack **a, t_ft_stack **b, const char *op);
t_ft_stack	**ft_gs(int mode, int n, t_ft_stack *s);

#endif
