/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 09:45:38 by yabad             #+#    #+#             */
/*   Updated: 2023/02/02 10:59:56 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/get_next_line.h"

void	performe_instruction2(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(inst, "pa\n", 3))
		_push(b, a);
	else if (!ft_strncmp(inst, "pb\n", 3))
		_push(a, b);
	else if (!ft_strncmp(inst, "sa\n", 3))
		_swap(a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		_swap(b);
	else if (!ft_strncmp(inst, "ss\n", 3))
	{
		_swap(a);
		_swap(b);
	}
	else
	{
		if (a->top)
			freemem(NULL, NULL, a->top);
		if (b->top)
			freemem(NULL, NULL, b->top);
		free(inst);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	performe_instruction(char *inst, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(inst, "ra\n", 3))
		_rotate(a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		_rotate(b);
	else if (!ft_strncmp(inst, "rr\n", 3))
	{
		_rotate(a);
		_rotate(b);
	}
	else if (!ft_strncmp(inst, "rra\n", 4))
		_r_rotate(a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		_r_rotate(b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
	{
		_r_rotate(a);
		_r_rotate(b);
	}
	else
		performe_instruction2(inst, a, b);
}

void	start_exec_instructions(char **splited)
{
	t_stack	a;
	t_stack	b;
	char	*inst;

	a = fill_stack(splited);
	b.top = NULL;
	inst = get_next_line(0);
	while (inst != NULL)
	{
		performe_instruction(inst, &a, &b);
		free(inst);
		inst = get_next_line(0);
	}
	if (is_sorted(&a) && is_empty(b))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	freemem(NULL, NULL, a.top);
	freemem(NULL, NULL, b.top);
}

int	main(int ac, char **av)
{
	char	**splited;

	splited = NULL;
	if (ac > 1)
	{
		splited = is_valid(join_args(av));
		if (splited)
			start_exec_instructions(splited);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
