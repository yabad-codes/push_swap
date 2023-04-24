/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:29:36 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 19:25:30 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// Macros
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

// Prototypes UTILS
char	*ft_strjoin_g(char *s1, char *s2);
void	*ft_memcpy_g(void *dst, const void *src, int len);
char	*ft_strchr_g(const char *s, int c);
int		ft_strlen_g(const char *s);

// Prototypes MAIN
char	*cleaner(char *container);
char	*first_line(char *container);
char	*read_from_file(int fd, char *container, int *rd);
char	*get_next_line(int fd);
#endif