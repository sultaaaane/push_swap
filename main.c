/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/16 16:44:27 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init(t_pushswap *ps, int ac)
{
	ps->size_a = ac - 1;
	ps->size_b = 0;
}

// int	main(int ac, char **av)
// {
// 	check_parse(ac,av);
	
// 	return (0);
// }
