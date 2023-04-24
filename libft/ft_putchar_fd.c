/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:05:04 by yabad             #+#    #+#             */
/*   Updated: 2022/10/14 15:20:32 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main()
// {
// 	int	fd;
//	int fd1;
//
// 	fd = open("file6.txt", O_CREAT | O_RDWR, S_IREAD | S_IWRITE);
// 	ft_putchar_fd('8', fd);
// 	fd1 = open("file7.txt", O_CREAT | O_RDWR, S_IREAD | S_IWRITE);
// 	ft_putchar_fd('5', fd);
// }