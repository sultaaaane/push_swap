/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/01 20:21:17 by mbentahi         ###   ########.fr       */
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

int	smallest_value(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	temp = stack;
	min = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
