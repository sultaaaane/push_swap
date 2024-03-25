/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/24 22:53:21 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, t_pushswap *ps, int flag)
{
	int	holder;

	if (ps->size_a < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, t_pushswap *ps, int flag)
{
	int	holder;

	if (ps->size_b < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_pushswap *ps)
{
	sa(stack_a, ps, 0);
	sb(stack_b, ps, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	if (ps->size_b == 0)
		return ;
	stack_addfront(stack_a, pop(stack_b));
	ps->size_a++;
	ps->size_b--;
	ft_printf("pa\n");
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_pushswap	ps;

	stack_a = NULL;
	stack_b = NULL;
	ps.size_b = 0;
	// check_parse(ac, av);
	push_to_stack(&stack_a, ac, av);
	if (is_sorted(stack_a) || is_dup(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	ps.size_a = stack_size(stack_a);
	// ft_printf("Stack A before sa: ");
	// print_stack(stack_a);
	sort_all(&stack_a, &stack_b, &ps);
	// sort_3(&stack_a, &ps);
	// ft_printf("Stack A after sa: ");
	// print_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
