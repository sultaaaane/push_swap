/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:32:15 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/05 10:15:49 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(t_pushswap *ps)
{
	int i;
	int j;
	char **tab;

	i = 1;
	while (i < ps->argc)
	{
		tab = ft_split(ps->argv[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (!ft_isdigit(tab[j]))
			{
				ft_free_tab(tab);
				return (0);
			}
			push_back(&ps->stack_a, ft_atoi(tab[j]));
			j++;
		}
		ft_free_tab(tab);
		i++;
	}
}