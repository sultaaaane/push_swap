/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/25 22:25:02 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **stack, t_pushswap *ps, int flag)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ps->size_b < 2)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	rra(stack_a, ps, 0);
	rrb(stack_b, ps, 0);
	ft_printf("rrr\n");
}

void	sort_2(t_stack **stack_a, t_pushswap *ps)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a, ps, 1);
}

void	sort_3_help(t_stack **stack, t_pushswap *ps)
{
	ra(stack, ps, 1);
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		sa(*stack, ps, 1);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		ra(stack, ps, 1);
}

void	sort_3(t_stack **stack, t_pushswap *ps)
{
	if (*stack == NULL || (*stack)->next == NULL
		|| (*stack)->next->next == NULL)
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		sa(*stack, ps, 1);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		sort_3_help(stack, ps);
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		sort_3_help(stack, ps);
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
	{
		sa(*stack, ps, 1);
		ra(stack, ps, 1);
	}
}
