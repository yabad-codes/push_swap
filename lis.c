/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:01:52 by yabad             #+#    #+#             */
/*   Updated: 2023/01/31 11:30:34 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extract_lis(int *number, int *dp, int *prev, t_vars *vars)
{
	int	max_dp;
	int	*lis;
	int	i;

	max_dp = find_max_arr(dp, vars);
	lis = (int *)malloc(dp[max_dp] * sizeof(int));
	if (!lis)
		return (NULL);
	i = dp[max_dp] - 1;
	while (i >= 0)
	{
		lis[i] = number[max_dp];
		max_dp = prev[max_dp];
		i--;
	}
	free(number);
	free(dp);
	free(prev);
	return (lis);
}

int	*find_lis(int *number, t_vars *vars)
{
	int	*dp;
	int	*prev;
	int	i;
	int	j;

	dp = (int *)malloc(vars->size * sizeof(int));
	prev = (int *)malloc(vars->size * sizeof(int));
	if (!dp || !prev)
		return (NULL);
	fill_arr(dp, prev, vars->size);
	i = 0;
	while (++i < vars->size)
	{
		j = -1;
		while (++j < i)
		{
			if (number[i] > number[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}
	return (extract_lis(number, dp, prev, vars));
}

int	*push_min_to_top(t_stack *stack, int min, t_vars *vars)
{
	t_stack	tmp;
	int		*arr;

	tmp = *stack;
	arr = from_stack_to_array(&tmp, vars->size);
	while (arr[0] != min)
	{
		if (vars->min_pos < (vars->size + 1) / 2)
			_rotate_arr(arr, vars->size);
		else
			_r_rotate_arr(arr, vars->size);
	}
	return (find_lis(arr, vars));
}
