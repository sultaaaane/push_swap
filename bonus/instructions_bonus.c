/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 21:08:54 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stack, t_pushswap *ps)
{
	int	holder;

	if (ps->size_a < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
}

void	sb(t_stack *stack, t_pushswap *ps)
{
	int	holder;

	if (ps->size_b < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_pushswap *ps)
{
	sa(stack_a, ps);
	sb(stack_b, ps);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	if (ps->size_b == 0)
		return ;
	stack_addfront(stack_a, pop(stack_b));
	ps->size_a++;
	ps->size_b--;
}
