/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions5_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:48 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 21:09:38 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	if (ps->size_a == 0)
		return ;
	stack_addfront(stack_b, pop(stack_a));
	ps->size_a--;
	ps->size_b++;
}

void	ra(t_stack **stack, t_pushswap *ps)
{
	t_stack	*temp;
	t_stack	*last;

	if (ps->size_a < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	rb(t_stack **stack, t_pushswap *ps)
{
	t_stack	*temp;
	t_stack	*last;

	if (ps->size_b < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	ra(stack_a, ps);
	rb(stack_b, ps);
}

void	rra(t_stack **stack, t_pushswap *ps)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ps->size_a < 2)
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
}
