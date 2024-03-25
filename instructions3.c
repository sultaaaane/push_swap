/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:23:51 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/25 05:41:28 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_value(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	temp = stack;
	max = temp->value;
	while (temp != NULL)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	indexing(t_stack *stack, int value)
{
	t_stack	*temp;
	int		index;

	temp = stack;
	index = 0;
	while (temp != NULL)
	{
		if (temp->value == value)
			return (index);
		temp = temp->next;
		index++;
	}
	return (index);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	int	smallest;
	int	index;

	while (stack_size(*stack_a) > 3)
	{
		smallest = smallest_value(*stack_a);
		index = indexing(*stack_a, smallest);
		if (index <= stack_size(*stack_a) / 2 && index != 0)
			ra(stack_a, ps, 1);
		else if (index >= stack_size(*stack_a) / 2 && index != 0)
			rra(stack_a, ps, 1);
		else
			pb(stack_a, stack_b, ps);
	}
	sort_3(stack_a, ps);
	while (!is_empty(*stack_b))
		pa(stack_a, stack_b, ps);
}

int	*push_array(t_stack *stack_a)
{
	int	*tab;
	int	i;

	tab = (int *)malloc(sizeof(int) * stack_size(stack_a));
	i = 0;
	while (stack_a != NULL)
	{
		tab[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	return (tab);
}
