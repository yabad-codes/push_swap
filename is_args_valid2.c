/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_args_valid2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:32:19 by yabad             #+#    #+#             */
/*   Updated: 2023/01/26 19:46:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_special_chars(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] == ' ' || ft_isdigit(arg[i]) \
			|| arg[i] == '-' || arg[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	is_plus_minus_valid(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] == '+' || number[i] == '-')
		{
			if (!number[i + 1] || \
				!ft_isdigit(number[i + 1]) || i != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_range_valid(char *number)
{
	if (ft_long_atoi(number) == 0 && ft_strlen(number) > 2)
		return (0);
	return (1);
}

int	is_number_valid(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		if (!is_plus_minus_valid(splited[i]) || !is_range_valid(splited[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_not_duplicated(char **splited)
{
	int	i;
	int	j;

	i = -1;
	while (splited[++i])
	{
		j = i;
		while (splited[++j])
		{
			if (ft_atoi(splited[i]) == ft_atoi(splited[j]))
				return (0);
		}
	}
	return (1);
}
