/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 21:09:24 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrb(t_stack **stack, t_pushswap *ps)
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
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	rra(stack_a, ps);
	rrb(stack_b, ps);
}
