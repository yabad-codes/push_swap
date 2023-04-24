/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:53:02 by yabad             #+#    #+#             */
/*   Updated: 2023/01/30 14:31:09 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstp;
	char	*srcp;

	if (!dst && !src)
		return (NULL);
	dstp = dst;
	srcp = (char *)src;
	i = 0;
	while (i < len)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dst);
}

// int	main()
// {
// 	//printf("%s", ft_memcpy(((void *)0), ((void *)0), 3));
// 	printf("%s", memcpy(((void *)0), ((void *)0), 3));
// }
