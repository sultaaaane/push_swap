/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:04:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/22 02:01:35 by mbentahi         ###   ########.fr       */
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
	t_stack *last;
	
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

t_stack *pop(t_stack **stack) 
{
    t_stack *temp; 
    
    if (*stack == NULL)
        return (NULL);
    temp = *stack;
    *stack = (*stack)->next;
    return (temp);
}

void print_stack(t_stack *stack) {
    while (stack != NULL) {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

int is_sorted(t_stack *stack)
{
	t_stack *temp;
	
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}