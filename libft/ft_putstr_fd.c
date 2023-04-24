/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:37:00 by yabad             #+#    #+#             */
/*   Updated: 2022/10/10 19:45:30 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// int	main()
// {
// 	int	fd;

// 	fd = open("./file2.txt", O_CREAT | O_RDWR , S_IREAD | S_IWRITE);
// 	ft_putstr_fd("Lola is cute", fd);
// 	close(fd);
// }