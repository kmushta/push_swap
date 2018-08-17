/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:46:13 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:46:15 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_UTILS_H
# define FT_SORT_UTILS_H

# include "ft_stack.h"

int		ft_issorted_a(t_ft_stack **s);
int		ft_issorted_b(t_ft_stack **s);
int		ft_sort_entropy(t_ft_stack **s, int i);

#endif
