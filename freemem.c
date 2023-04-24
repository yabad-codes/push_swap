/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:00:32 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 12:54:11 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freemem(char **ptr, void *ptr2, t_node *stack)
{
	int		i;
	t_node	*tmp;

	i = -1;
	if (ptr)
	{
		while (ptr[++i])
			free(ptr[i]);
		free(ptr);
	}
	if (ptr2)
		free(ptr2);
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
