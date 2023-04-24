/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:58:54 by yabad             #+#    #+#             */
/*   Updated: 2023/01/31 10:43:18 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	fill_stack(char **splited)
{
	t_stack	stack;
	int		i;

	i = 0;
	stack.top = NULL;
	while (splited[i])
		i++;
	while (--i >= 0)
		push(&stack, ft_long_atoi(splited[i]));
	freemem(splited, NULL, NULL);
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	pop(t_stack *stack)
{
	int		value;
	t_node	*tmp;

	if (!stack->top)
		return (-1);
	value = stack->top->value;
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	return (value);
}

int	peek(t_stack stack)
{
	if (!stack.top)
		return (-1);
	return (stack.top->value);
}

int	is_empty(t_stack stack)
{
	return (!stack.top);
}
