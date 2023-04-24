/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:13:09 by yabad             #+#    #+#             */
/*   Updated: 2023/02/02 12:40:16 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

enum {
	IMAX = 2147483647,
	IMIN = -2147483648,
	HT = 9,
	CR = 13,
	SP = 32
};

int	is_int(long int n)
{
	if (n <= IMAX && n >= IMIN)
		return (1);
	return (0);
}

long int	ft_long_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	n;

	sign = 1;
	i = 0;
	n = 0;
	while ((str[i] >= HT && str[i] <= CR) || str[i] == SP)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (is_int(n * sign))
		return (n * sign);
	return (0);
}
