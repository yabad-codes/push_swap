/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_runner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:03:53 by yabad             #+#    #+#             */
/*   Updated: 2023/01/30 10:10:30 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helper(char *action, t_stack *a, t_stack *b, int len_action)
{
	(void)b;
	if (!ft_strncmp(action, "ra", len_action) || \
		!ft_strncmp(action, "rb", len_action))
		_rotate(a);
	else if (!ft_strncmp(action, "rr", len_action))
	{
		_rotate(a);
		_rotate(b);
	}
	else if (!ft_strncmp(action, "rra", len_action) || \
			!ft_strncmp(action, "rrb", len_action))
		_r_rotate(a);
	else if (!ft_strncmp(action, "rrr", len_action))
	{
		_r_rotate(a);
		_r_rotate(b);
	}
}

void	action_runner(char *action, t_stack *a, t_stack *b)
{
	int	len_action;

	len_action = (int)ft_strlen(action);
	if (!ft_strncmp(action, "sa", len_action) || \
		!ft_strncmp(action, "sb", len_action))
		_swap(a);
	else if (!ft_strncmp(action, "ss", len_action))
	{
		_swap(a);
		_swap(b);
	}
	else if (!ft_strncmp(action, "pa", len_action))
		_push(b, a);
	else if (!ft_strncmp(action, "pb", len_action))
		_push(a, b);
	helper(action, a, b, len_action);
	ft_putstr_fd(action, 1);
	ft_putchar_fd('\n', 1);
}
