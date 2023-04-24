/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:32:19 by yabad             #+#    #+#             */
/*   Updated: 2023/02/01 10:17:37 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_args(char **av)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	joined = NULL;
	while (av[++i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
		{
			if (joined)
				free(joined);
			return (NULL);
		}
		joined = ft_strjoin(joined, av[i]);
	}
	return (joined);
}
