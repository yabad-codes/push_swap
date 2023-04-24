/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:11:40 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 13:14:06 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_max(int *arr, int size)
{
	int	i;
	int	max;

	i = 1;
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	get_min_pos(int *arr, int size)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < size)
	{
		if (arr[i] < arr[min])
			min = i;
		i++;
	}
	return (min);
}

int	get_perfect_position(int n, int *arr, int size)
{
	int	i;
	int	max;

	i = 0;
	max = get_max(arr, size);
	if (n > max)
		return (get_min_pos(arr, size));
	while (i < size)
	{
		if (arr[i] < n && arr[i + 1] > n)
			return (i + 1);
		i++;
	}
	return (0);
}
