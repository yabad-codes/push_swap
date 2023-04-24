/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:48:29 by yabad             #+#    #+#             */
/*   Updated: 2023/01/26 19:46:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*from_stack_to_array(t_stack *stack, int size)
{
	t_stack	tmp;
	int		*arr;

	tmp = *stack;
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	size = 0;
	while (tmp.top)
	{
		arr[size] = tmp.top->value;
		size++;
		tmp.top = tmp.top->next;
	}
	return (arr);
}

void	_rotate_arr(int *arr, int size)
{
	int	i;
	int	value;

	i = 1;
	value = arr[0];
	while (i < size)
	{
		arr[i - 1] = arr[i];
		i++;
	}
	arr[i - 1] = value;
}

void	_r_rotate_arr(int *arr, int size)
{
	int	i;
	int	value;

	i = size - 1;
	value = arr[i];
	while (i >= 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = value;
}

int	find_max_arr(int *dp, t_vars *vars)
{
	int	max;
	int	i;

	max = 0;
	i = 1;
	while (i < vars->size)
	{
		if (dp[max] < dp[i])
			max = i;
		i++;
	}
	vars->lis_len = dp[max];
	return (max);
}

void	fill_arr(int *dp, int *prev, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		dp[i] = 1;
		prev[i] = -1;
	}
}
