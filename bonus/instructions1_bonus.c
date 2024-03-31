/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:21:42 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/29 11:19:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_to_a(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	int	highest;
	int	position;

	highest = find_highest(*stack_b);
	position = find_position(*stack_b, highest);
	while (stack_size(*stack_b) > 0)
	{
		if (highest == (*stack_b)->value)
		{
			pa(stack_a, stack_b, ps);
			if (stack_size(*stack_b) > 0)
			{
				highest = find_highest(*stack_b);
				position = find_position(*stack_b, highest);
			}
		}
		else
		{
			if (position <= (stack_size(*stack_b) / 2)
				&& highest != (*stack_b)->value)
				rb(stack_b, ps, 1);
			else
				rrb(stack_b, ps, 1);
		}
	}
}

int	find_index(t_stack *stack, int index, int p)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index <= index || stack->index <= index + p)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort_helper(t_stack *stack, int *size, int *p)
{
	int	*tab;

	*size = stack_size(stack);
	tab = push_array(stack);
	sort_array(tab, *size);
	array_indexing(stack, tab);
	if (*size < 250)
		*p = 15;
	else
		*p = 30;
	free(tab);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	int	i;
	int	p;
	int	num;

	sort_helper(*stack_a, &num, &p);
	i = 0;
	while (i < num)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, ps);
			rb(stack_b, ps, 1);
			i++;
		}
		else if ((*stack_a)->index <= i + p)
		{
			pb(stack_a, stack_b, ps);
			i++;
		}
		else if (find_index(*stack_a, i, p) < stack_size(*stack_a) / 2)
			ra(stack_a, ps, 1);
		else
			rra(stack_a, ps, 1);
	}
	ft_push_to_a(stack_a, stack_b, ps);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
