/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:37:06 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:37:08 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops_def.h"
#include "push_swap.h"
#include "libft_funcs.h"
#include "ft_validate.h"
#include "ft_sort_utils.h"
#include "ft_debug.h"
#include <unistd.h>
#include <stdlib.h>

t_ft_stack	*ft_read_s(char **av)
{
	t_ft_stack *s;

	if (!av)
		return (0);
	s = create_ft_stack();
	while (*av)
	{
		ft_stack_push_back(&s, ft_atoi(*av));
		av++;
	}
	return (s);
}

int			ft_str_op(char *s)
{
	if (ft_strcmp(s, "sa"))
		return (FT_SA);
	if (ft_strcmp(s, "sb"))
		return (FT_SB);
	if (ft_strcmp(s, "ss"))
		return (FT_SS);
	if (ft_strcmp(s, "pa"))
		return (FT_PA);
	if (ft_strcmp(s, "pb"))
		return (FT_PB);
	if (ft_strcmp(s, "ra"))
		return (FT_RA);
	if (ft_strcmp(s, "rb"))
		return (FT_RB);
	if (ft_strcmp(s, "rr"))
		return (FT_RR);
	if (ft_strcmp(s, "rra"))
		return (FT_RRA);
	if (ft_strcmp(s, "rrb"))
		return (FT_RRB);
	if (ft_strcmp(s, "rrr"))
		return (FT_RRR);
	if (!*s)
		return (-1);
	return (-2);
}

int			ft_read_op(void)
{
	char	buff[4];
	int		i;
	int		q;

	i = 0;
	while ((q = read(0, buff + i, 1)))
	{
		if (*(buff + i) == '\n')
		{
			*(buff + i) = 0;
			return (ft_str_op(buff));
		}
		i++;
	}
	if (q == 0)
		return (-1);
	return (0);
}

t_ft_stack	*ft_read_ops(void)
{
	t_ft_stack	*op;
	int			i;

	op = create_ft_stack();
	i = ft_read_op();
	while (i >= 0)
	{
		ft_stack_push_back(&op, i);
		i = ft_read_op();
	}
	if (i == -1)
		return (op);
	free(op);
	return (0);
}

int			main(int ac, char **argv)
{
	t_ft_stack	*s;
	t_ft_stack	*op;
	char		**av;

	if (ac < 2 || (ac == 2 && ft_strcmp(*(argv + 1), "-v")))
		return (ft_usage(*argv));
	ac--;
	av = argv + 1;
	if (ft_strcmp(*av, "-v"))
	{
		ft_v(1);
		av++;
		ac--;
	}
	if (ac == 1 && !(av = ft_strsplit(*av, ' ', &ac)))
		return (ft_error());
	if (!ft_check_list(ac, av))
		return (ft_error());
	if (!ft_check_dups((s = ft_read_s(av))))
		return (ft_error());
	if (!(op = ft_read_ops()))
		return (ft_error());
	if (ft_app(&s, &op))
		return (ft_putendl_fd(1, "OK") * 0);
	return (ft_putendl_fd(1, "KO") * 0);
}
