/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:41:36 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:41:37 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPS_DEF_H
# define FT_OPS_DEF_H

# include "ft_stack.h"

# define FT_SA 0
# define FT_SB 1
# define FT_SS 2
# define FT_PA 3
# define FT_PB 4
# define FT_RA 5
# define FT_RB 6
# define FT_RR 7
# define FT_RRA 8
# define FT_RRB 9
# define FT_RRR 10

void	ft_sa(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_sb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_pa(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_pb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_ra(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_rb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_rra(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);
void	ft_rrb(t_ft_stack **a, t_ft_stack **b, t_ft_stack **op, int mode);

#endif
