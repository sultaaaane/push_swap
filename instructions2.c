/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:22:28 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/25 05:39:43 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	array_indexing(t_stack *stack_a, int *tab)
{
	t_stack	*temp;
	int		i;
	int		j;

	temp = stack_a;
	i = 0;
	while (temp != NULL)
	{
		j = 0;
		while (j < stack_size(stack_a))
		{
			if (temp->value == tab[j])
				temp->index = j;
			j++;
		}
		temp = temp->next;
	}
}

void	sort_array(int *tab, int size)
{
	int	i;
	int	j;
	int	holder;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				holder = tab[i];
				tab[i] = tab[j];
				tab[j] = holder;
			}
			j++;
		}
		i++;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	int	index;
	int	highest;

	highest = biggest_value(*stack_b);
	index = indexing(*stack_b, highest);
	while (stack_size(*stack_b) > 0)
	{
		if (highest == (*stack_b)->value)
		{
			pa(stack_a, stack_b, ps);
			if (stack_size(*stack_b) > 0)
			{
				highest = biggest_value(*stack_b);
				index = indexing(*stack_b, highest);
			}
		}
		else
		{
			if (index <= stack_size(*stack_b) / 2
				&& highest != (*stack_b)->value)
				rb(stack_b, ps, 1);
			else
				rrb(stack_a, ps, 1);
		}
	}
}

int	find_position(t_stack *stack, int value)
{
	int	position;

	position = 0;
	while (value != stack->value)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

int	find_highest(t_stack *stack)
{
	int	highest;

	highest = stack->value;
	while (stack)
	{
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}
