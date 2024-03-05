/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:04:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/05 00:54:45 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void initializer(t_stack *stack)
{
	stack->top = NULL;	
}

int isempty(t_stack *stack)
{
	return (stack->top == NULL);
}

void push(t_stack *stack,int value)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top;
	stack->top = new;
}

int pop(t_stack *stack)
{
	int value;
	t_node *temp;
	if(isempty(stack))
	{
		ft_printf("underflow");
		exit(EXIT_FAILURE);
	}
	value = stack->top->value;
	temp = stack->top->next;
	stack->top = stack->top->next;
	free(temp);
	return (value);
}

void print_stack(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	while (!current)
	{
		ft_printf("%d",current->value);
		current = current->next;
	}
	ft_printf("\n");
}
void pa(t_stack *stack_a,t_stack *stack_b)
{
	if (!isempty(stack_b))
		push(stack_a,pop(stack_b));
}