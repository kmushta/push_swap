/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:48:55 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:48:56 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int		ft_putstr_fd(int fd, const char *s)
{
	return (write(fd, s, ft_strlen(s)));
}

int		ft_putendl_fd(int fd, const char *s)
{
	int		i;

	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i + 1);
}

int		ft_atoi(const char *s)
{
	int		result;
	char	sign;

	result = 0;
	sign = 0;
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	if (*s == '-')
	{
		sign = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + *s++ - 48;
	if (sign)
		return (-result);
	return (result);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (!*s1 && !*s2)
		return (1);
	return (0);
}
