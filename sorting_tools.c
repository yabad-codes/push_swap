/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:12:14 by yabad             #+#    #+#             */
/*   Updated: 2023/01/26 19:46:33 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp.top)
	{
		i++;
		tmp.top = tmp.top->next;
	}
	return (i);
}

int	minimum_value_of_stack(t_stack *stack, int *pos)
{
	t_stack	tmp;
	int		min;
	int		index;

	tmp = *stack;
	min = peek(tmp);
	*pos = 0;
	index = 0;
	while (tmp.top->next)
	{
		if (tmp.top->next->value < min)
		{
			*pos = index + 1;
			min = tmp.top->next->value;
		}
		tmp.top = tmp.top->next;
		index++;
	}
	return (min);
}

int	is_sorted(t_stack *stack)
{
	t_stack	tmp;

	tmp = *stack;
	while (tmp.top)
	{
		if (tmp.top->next && tmp.top->value > tmp.top->next->value)
			return (0);
		tmp.top = tmp.top->next;
	}
	return (1);
}
