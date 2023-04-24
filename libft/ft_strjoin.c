/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:03:23 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 09:48:11 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *)malloc(i + j + 2);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, i);
	ft_memcpy(s + i, s2, j);
	s[i + j] = ' ';
	s[i + j + 1] = '\0';
	free(s1);
	return (s);
}
