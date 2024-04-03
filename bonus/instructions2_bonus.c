/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:22:28 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 23:21:34 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	return (ft_strncmp(str1, str2, ft_strlen(str1) + 1));
}

int	check_instructions(char *str, t_stack **stack_a, t_stack **stack_b,
		t_pushswap *ps)
{
	if (!ft_strcmp(str, "pa\n"))
		return (pa(stack_a, stack_b, ps), 0);
	else if (!ft_strcmp(str, "pb\n"))
		return (pb(stack_a, stack_b, ps), 0);
	else if (!ft_strcmp(str, "sa\n"))
		return (sa(*stack_a, ps), 0);
	else if (!ft_strcmp(str, "sb\n"))
		return (sb(*stack_b, ps), 0);
	else if (!ft_strcmp(str, "ss\n"))
		return (ss(*stack_a, *stack_b, ps), 0);
	else if (!ft_strcmp(str, "ra\n"))
		return (ra(stack_a, ps), 0);
	else if (!ft_strcmp(str, "rb\n"))
		return (rb(stack_b, ps), 0);
	else if (!ft_strcmp(str, "rr\n"))
		return (rr(stack_a, stack_b, ps), 0);
	else if (!ft_strcmp(str, "rra\n"))
		return (rra(stack_a, ps), 0);
	else if (!ft_strcmp(str, "rrb\n"))
		return (rrb(stack_b, ps), 0);
	else if (!ft_strcmp(str, "rrr\n"))
		return (rrr(stack_a, stack_b, ps), 0);
	else
		return (1);
}

int	get_instructions(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	char	*temp;

	temp = get_next_line(0);
	if (temp == NULL)
	{
		if (is_sorted(*stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		return (free_stack(stack_a), free_stack(stack_b),
			exit(EXIT_FAILURE), 0);
	}
	while (temp != NULL)
	{
		if (temp[0] == '\n')
			return (free(temp), 0);
		if (check_instructions(temp, stack_a, stack_b, ps))
			return (free(temp), 0);
		free(temp);
		temp = get_next_line(0);
	}
	return (1);
}

void	main_helper(t_stack *stack_a, t_stack *stack_b, t_pushswap *ps)
{
	if (is_dup(stack_a))
		return (free_stack(&stack_a), exit(EXIT_FAILURE));
	if (!get_instructions(&stack_a, &stack_b, ps))
		return (write(2, "Error\n", 6), free_stack(&stack_a),
			free_stack(&stack_b), exit(EXIT_FAILURE));
	if (is_sorted(stack_a) && stack_size(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
}
