/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:14:54 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 14:41:18 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, t_arr *arr)
{
	arr->s_a = stack_size(a);
	arr->s_b = stack_size(b);
	arr->a = from_stack_to_array(a, arr->s_a);
	arr->b = from_stack_to_array(b, arr->s_b);
}
