/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:59:33 by yabad             #+#    #+#             */
/*   Updated: 2023/01/31 11:40:23 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_swap(t_stack *stack)
{
	int	a;
	int	b;

	if (stack_size(stack) > 1)
	{
		a = pop(stack);
		b = pop(stack);
		push(stack, a);
		push(stack, b);
	}
}

void	_push(t_stack *from, t_stack *to)
{
	if (stack_size(from) > 0)
		push(to, pop(from));
}

void	_rotate(t_stack *stack)
{
	t_stack	tmp;
	int		value;

	if (stack_size(stack) > 1)
	{
		value = pop(stack);
		tmp.top = NULL;
		while (stack->top)
			push(&tmp, pop(stack));
		push(stack, value);
		while (tmp.top)
			push(stack, pop(&tmp));
	}
}

void	_r_rotate(t_stack *stack)
{
	t_stack	tmp;
	int		value;

	if (stack_size(stack) > 1)
	{
		tmp.top = NULL;
		while (stack->top)
			push(&tmp, pop(stack));
		value = pop(&tmp);
		while (tmp.top)
			push(stack, pop(&tmp));
		push(stack, value);
	}
}
