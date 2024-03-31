/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/29 11:19:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pushswap	ps;
	int i;

	ps.size_b = 0;
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
	if (is_dup(stack_a) || is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	ps.size_a = stack_size(stack_a);
	print_stack(stack_a);
	if (ps.size_a == 2)
		sort_2(&stack_a, &ps);
	else if (ps.size_a == 3)
		sort_3(&stack_a, &ps);
	else if (ps.size_a <= 5)
		sort_5(&stack_a, &stack_b, &ps); // doesn't sort 5 2 1 3 4 
	else
		sort_all(&stack_a, &stack_b, &ps);
	print_stack(stack_a);
	free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
	return (0);
}
