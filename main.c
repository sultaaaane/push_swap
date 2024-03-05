/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/05 10:15:37 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(t_pushswap *ps)
{
}

void	ps_init(t_pushswap *ps, int ac, char **av)
{
	ps->argc = ac;
	ps->argv = av;
	ps->size_a = ac - 1;
	ps->size_b = 0;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
}

int	main(int ac, char **av)
{
	t_pushswap	ps;

	ps_init(&ps, ac, av);
	if (ac > 1)
	{
		if (!init_stack(&ps))
			return (0);
		if (!check_duplicates(&ps))
			return (0);
		if (!check_args(&ps))
			return (0);
		if (!check_sorted(&ps))
		{
			if (ps.size_a == 2)
				sort_two(&ps);
			else if (ps.size_a == 3)
				sort_three(&ps);
			else if (ps.size_a == 4)
				sort_four(&ps);
			else if (ps.size_a == 5)
				sort_five(&ps);
			else
				sort(&ps);
		}
	}
	free_stack(&ps);
	return (0);
}
