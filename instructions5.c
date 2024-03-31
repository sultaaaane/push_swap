/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:48 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/31 15:12:22 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	if (ps->size_a == 0)
		return ;
	stack_addfront(stack_b, pop(stack_a));
	ps->size_a--;
	ps->size_b++;
	ft_putstr_fd("pb\n",2);
}

void	ra(t_stack **stack, t_pushswap *ps, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	if (ps->size_a < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (flag)
		ft_putstr_fd("ra\n",2);
}

void	rb(t_stack **stack, t_pushswap *ps, int flag)
{
	t_stack	*temp;
	t_stack	*last;

	if (ps->size_b < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (flag)
		ft_putstr_fd("rb\n",2);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps)
{
	ra(stack_a, ps, 0);
	rb(stack_b, ps, 0);
	ft_putstr_fd("rr\n",2);
}

void	rra(t_stack **stack, t_pushswap *ps, int flag)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ps->size_a < 2)
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
	if (flag)
		ft_putstr_fd("rra\n", 2);
}
