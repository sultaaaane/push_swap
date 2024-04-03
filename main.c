/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/03 09:14:19 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 12)
		return (1);
	return (0);
}

void	main_helper(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	if (ps->size_a == 2)
		sort_2(stack_a, ps);
	else if (ps->size_a == 3)
		sort_3(stack_a, ps);
	else if (ps->size_a <= 5)
		sort_5(stack_a, stack_b, ps);
	else
		sort_all(stack_a, stack_b, ps);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pushswap	ps;
	int			i;

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
	main_helper(&stack_a, &stack_b, &ps);
	free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
	return (0);
}
