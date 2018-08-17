/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:49:15 by kmushta           #+#    #+#             */
/*   Updated: 2018/02/04 13:49:16 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FUNCS_H
# define LIBFT_FUNCS_H

int		ft_strlen(const char *s);
int		ft_putstr_fd(int fd, const char *s);
int		ft_putendl_fd(int fd, const char *s);
int		ft_atoi(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_strsplit(char const *s, char c, int *len);

#endif
