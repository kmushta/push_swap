/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:48:30 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:48:31 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_H
# define FT_VALIDATE_H

# include "ft_stack.h"

int			ft_check_list(int ac, char **av);
int			ft_check_dups(t_ft_stack *s);
void		ft_app_op(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op);
int			ft_app(t_ft_stack **s, t_ft_stack **op);

#endif
