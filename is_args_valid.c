/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_args_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:40:27 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 10:13:26 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**is_valid(char *arg)
{
	char	**splited;

	if (arg == NULL)
		return (NULL);
	splited = ft_split(arg, ' ');
	if (!is_special_chars(arg) || \
		!is_number_valid(splited) || \
		!is_not_duplicated(splited))
	{
		freemem(splited, arg, NULL);
		return (NULL);
	}
	free(arg);
	return (splited);
}
