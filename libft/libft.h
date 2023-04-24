/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:48:08 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 19:41:05 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int			ft_isdigit(int c);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t len);
int			ft_atoi(const char *str);
long int	ft_long_atoi(const char *str);

char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif