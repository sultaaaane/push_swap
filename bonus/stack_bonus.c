/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:04:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/29 11:19:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stack_new(int value)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void	stack_addfront(t_stack **stack, t_stack *new_s)
{
	if (!new_s)
		return ;
	new_s->next = *stack;
	*stack = new_s;
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_addback(t_stack **stack, t_stack *new_s)
{
	t_stack	*last;

	if (!new_s)
		return ;
	if (!*stack)
	{
		*stack = new_s;
		return ;
	}
	last = stack_last(*stack);
	last->next = new_s;
}
