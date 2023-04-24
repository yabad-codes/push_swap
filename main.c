/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:56:18 by yabad             #+#    #+#             */
/*   Updated: 2023/02/04 12:33:35 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**splited;

	splited = NULL;
	if (ac > 1)
	{
		splited = is_valid(join_args(av));
		if (splited)
			start_sorting(splited);
		else
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
