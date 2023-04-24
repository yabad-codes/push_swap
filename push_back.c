/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:23:05 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 18:01:05 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_perfect_count(int *count, int ia, int ib, t_arr *arr)
{
	int	i;

	i = 0;
	while (ia-- && ib--)
		i++;
	*count = i + ia + ib;
	ia += i;
	ib += i;
	i = 0;
	while ((arr->s_a - ia++) && (arr->s_b - ib++))
		i++;
	*count = get_min(*count, i + (arr->s_a - ia) + (arr->s_b - ib));
	ia -= i;
	ib -= i;
	*count = get_min(*count, get_min(ib, arr->s_b - ib) + \
			ft_max(ia, arr->s_a - ia));
	*count = get_min(*count, (get_min(ib, arr->s_b - ib) + \
			get_min(ia, arr->s_a - ia)));
	*count = get_min(*count, (ft_max(ib, arr->s_b - ib) + \
			ft_max(ia, arr->s_a - ia)));
	*count = get_min(*count, (ft_max(ib, arr->s_b - ib) + \
			get_min(ia, arr->s_a - ia)));
}

void	update_item(t_pos *pos, t_arr *arr, int ib, int ia)
{
	get_perfect_count(&pos->count, ia, ib, arr);
	if (ia < arr->s_a - ia)
	{
		pos->na = ia;
		pos->oa = R;
	}
	else
	{
		pos->na = arr->s_a - ia;
		pos->oa = RR;
	}
	if (ib < arr->s_b - ib)
	{
		pos->nb = ib;
		pos->ob = R;
	}
	else
	{
		pos->nb = arr->s_b - ib;
		pos->ob = RR;
	}
}

void	get_item_to_push(t_arr *arr, t_pos *pos)
{
	int	ib;
	int	ia;
	int	old_count;

	ib = 0;
	old_count = pos->count;
	while (ib < arr->s_b)
	{
		ia = get_perfect_position(arr->b[ib], arr->a, arr->s_a);
		get_perfect_count(&pos->count, ia, ib, arr);
		if (pos->count < old_count)
		{
			old_count = pos->count;
			update_item(pos, arr, ib, ia);
		}
		ib++;
	}
	free(arr->a);
	free(arr->b);
}

void	update_stacks(t_stack *a, t_stack *b, t_pos *pos)
{
	while (pos->na && pos->nb && (pos->oa == pos->ob))
	{
		if (pos->oa == R)
			action_runner("rr", a, b);
		else
			action_runner("rrr", a, b);
		pos->na = (pos->nb--, pos->na - 1);
	}
	while (pos->na)
	{
		if (pos->oa == R)
			action_runner("ra", a, NULL);
		else
			action_runner("rra", a, NULL);
		pos->na--;
	}
	while (pos->nb)
	{
		if (pos->ob == R)
			action_runner("rb", b, NULL);
		else
			action_runner("rrb", b, NULL);
		pos->nb--;
	}
	action_runner("pa", a, b);
}

void	push_to_stack_a(t_stack *a, t_stack *b)
{
	t_arr	arr;
	t_pos	pos;

	while (!is_empty(*b))
	{
		init(a, b, &arr);
		pos.count = arr.s_a + arr.s_b;
		get_item_to_push(&arr, &pos);
		update_stacks(a, b, &pos);
	}
}
