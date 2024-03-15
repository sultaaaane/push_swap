/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:04:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/15 16:42:14 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *stack;
	
	stack = (t_stack*)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

void stack_addfront(t_stack **stack,t_stack *new_s)
{
	if (!new_s)
		return ;
	if (*stack == NULL)
	{
		*stack = new_s;
		return ;
	}
	new_s->next = *stack;
	*stack = new_s;
}

t_stack *stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void stack_addback(t_stack **stack,t_stack *new_s)
{
	t_stack *temp;
	
	temp = *stack;			
	if (!new_s)
		return ;
	if (*stack == NULL)
	{
		*stack = new_s;
		return;
	}
	temp = stack_last(temp);
	temp->next = new_s;
}

long pop(t_stack **stack)
{
	int value;
	t_stack *temp; 
	
	if (*stack == NULL)
		return (ft_printf("stack underflow"),2147483648);
	value = (*stack)->value;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (value);
}
