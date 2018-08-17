/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:47:51 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:47:52 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct			s_ft_stack
{
	int					value;
	struct s_ft_stack	*next;
	struct s_ft_stack	*prev;
}						t_ft_stack;

t_ft_stack				*new_ft_stack(int value);
t_ft_stack				*create_ft_stack(void);
void					ft_delete_stack(t_ft_stack **s);
t_ft_stack				*clone_ft_stack(t_ft_stack **s);
void					ft_stack_push(t_ft_stack **s, int value);
void					ft_stack_push_back(t_ft_stack **s, int value);
int						ft_stack_pop(t_ft_stack **s);
int						ft_stack_pop_back(t_ft_stack **s);
int						ft_swap(t_ft_stack **s);
int						ft_shift(t_ft_stack **s);
int						ft_unshift(t_ft_stack **s);
int						ft_push(t_ft_stack **a, t_ft_stack **b);

#endif
