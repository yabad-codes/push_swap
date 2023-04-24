/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:46:42 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 14:47:56 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *sa)
{
	int	a;
	int	b;
	int	c;

	a = sa->top->value;
	b = sa->top->next->value;
	c = sa->top->next->next->value;
	if (a < b && b > c)
	{
		action_runner("rra", sa, NULL);
		if (c > a)
			action_runner("sa", sa, NULL);
	}
	else if (a > b && c < a)
	{
		action_runner("ra", sa, NULL);
		if (b > c)
			action_runner("sa", sa, NULL);
	}
	else if (a > b && b < c && c > a)
		action_runner("sa", sa, NULL);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;
	int	i;

	i = 2;
	pos = 0;
	while (i)
	{
		while (minimum_value_of_stack(a, &pos) != peek(*a))
		{
			if (pos <= (stack_size(a) / 2))
				action_runner("ra", a, NULL);
			else
				action_runner("rra", a, NULL);
		}
		action_runner("pb", a, b);
		i--;
	}
	sort_three(a);
	action_runner("pa", a, b);
	action_runner("pa", a, b);
}
