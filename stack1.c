/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 05:48:38 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/25 05:49:06 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	return (temp);
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!temp)
		return (1);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}
