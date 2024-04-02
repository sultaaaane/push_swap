/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 21:30:46 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pushswap	ps;
	int			i;

	check_parse(ac, av);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (av[i] && av[i][0] != '\0')
	{
		if (isallwhitespace(av[i]) || av[i][0] == '\0')
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	push_to_stack(&stack_a, ac, av);
	ps.size_a = stack_size(stack_a);
	ps.size_b = 0;
	main_helper(stack_a, stack_b, &ps);
	return (0);
}
