/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/15 03:01:31 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	parsing(t_pushswap *ps)
// {
// }

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
	check_parse(ac,av);
	
	return (0);
}
