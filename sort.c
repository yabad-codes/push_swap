/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:56:18 by yabad             #+#    #+#             */
/*   Updated: 2023/02/04 12:07:47 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_belong(int n, int *lis, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	push_to_stack_b(t_stack *a, t_stack *b, t_vars *vars)
{
	b->top = NULL;
	while (stack_size(b) != vars->size - vars->lis_len)
	{
		if (!is_belong(peek(*a), vars->lis, vars->lis_len))
			action_runner("pb", a, b);
		else
			action_runner("ra", a, NULL);
	}
	free(vars->lis);
}

void	_xs(t_stack *a, t_stack *b, t_vars *vars)
{
	if (vars->size == 2 && !is_sorted(a))
		action_runner("sa", a, NULL);
	else if (vars->size == 3 && !is_sorted(a))
		sort_three(a);
	else if (vars->size == 5 && !is_sorted(a))
		sort_five(a, b);
	else
	{
		freemem(NULL, NULL, a->top);
		exit(0);
	}
}

void	_3xl(t_stack stack_a, t_stack stack_b, t_vars vars)
{
	(void)stack_b;
	if (!is_sorted(&stack_a))
	{
		vars.lis = push_min_to_top(&stack_a, \
		minimum_value_of_stack(&stack_a, &vars.min_pos), &vars);
		push_to_stack_b(&stack_a, &stack_b, &vars);
		push_to_stack_a(&stack_a, &stack_b);
		minimum_value_of_stack(&stack_a, &vars.min_pos);
		while (!is_sorted(&stack_a))
		{
			if (vars.min_pos < (vars.size + 1) / 2)
				action_runner("ra", &stack_a, NULL);
			else
				action_runner("rra", &stack_a, NULL);
		}
		freemem(NULL, NULL, stack_a.top);
	}
}

void	start_sorting(char **splited)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_vars	vars;

	stack_a = fill_stack(splited);
	stack_b.top = NULL;
	vars.size = stack_size(&stack_a);
	if (is_sorted(&stack_a))
	{
		freemem(NULL, NULL, stack_a.top);
		exit(0);
	}
	if (vars.size <= 3 || vars.size == 5)
	{
		_xs(&stack_a, &stack_b, &vars);
		freemem(NULL, NULL, stack_a.top);
	}
	else
		_3xl(stack_a, stack_b, vars);
}
