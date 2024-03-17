/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/16 17:01:30 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stack,t_pushswap *ps,int flag)
{
	int holder;

	if (ps->size_a < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
	if (flag == 1)
		ft_printf("sa\n");
}

void sb(t_stack *stack,t_pushswap *ps,int flag)
{
	int holder;

	if (ps->size_b < 2)
		return ;
	holder = stack->value;
	stack->value = stack->next->value;
	stack->next->value = holder;
	if (flag == 1)
		ft_printf("sb\n");
}

void ss(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps)
{
	sa(stack_a,ps,0);
	sb(stack_b,ps,0);
	ft_printf("ss\n");
}

void pa(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps)
{
	int value;

	if (ps->size_b == 0)
		return ;
	value = pop(&stack_b);
	stack_addfront(&stack_a,value);
	ps->size_a++;
	ps->size_b--;
	ft_printf("pa\n");
}

void pb(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps)
{
	int value;

	if (ps->size_a == 0)
		return ;
	value = pop(&stack_a);
	stack_addfront(&stack_b,value);
	ps->size_a--;
	ps->size_b++;
	ft_printf("pb\n");
}

void ra(t_stack **stack,t_pushswap *ps,int flag)
{
	t_stack *temp;
	t_stack *last;

	if (ps->size_a < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}

void rb(t_stack **stack,t_pushswap *ps,int flag)
{
	t_stack *temp;
	t_stack *last;

	if (ps->size_b < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}

void rr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	ra(stack_a,ps,0);
	rb(stack_b,ps,0);
	ft_printf("rr\n");
}

void rra(t_stack **stack,t_pushswap *ps,int flag)
{
	t_stack *temp;
	t_stack *last;

	if (ps->size_a < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	while (temp->next != last)
		temp = temp->next;
	last->next = temp;
	*stack = last;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("rra\n");
}

void rrb(t_stack **stack,t_pushswap *ps,int flag)
{
	t_stack *temp;
	t_stack *last;

	if (ps->size_b < 2)
		return ;
	temp = *stack;
	last = stack_last(temp);
	while (temp->next != last)
		temp = temp->next;
	last->next = temp;
	*stack = last;
	temp->next = NULL;
	if (flag == 1)
		ft_printf("rrb\n");
}

void rrr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	rra(stack_a,ps,0);
	rrb(stack_b,ps,0);
	ft_printf("rrr\n");
}

int main() {
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_pushswap ps;

	// Initialize the pushswap struct and the stacks
	ps.size_a = 6;
	ps.size_b = 6;
	stack_a = NULL;
	stack_b = NULL;

	// Push 6 numbers to stack_a
	stack_addfront(&stack_a, 1);
	stack_addfront(&stack_a, 2);
	stack_addfront(&stack_a, 3);
	stack_addfront(&stack_a, 4);
	stack_addfront(&stack_a, 5);
	stack_addfront(&stack_a, 6);

	// stack_addfront 6 numbers to stack_b
	stack_addfront(&stack_b, 7);
	stack_addfront(&stack_b, 8);
	stack_addfront(&stack_b, 9);
	stack_addfront(&stack_b, 10);
	stack_addfront(&stack_b, 11);
	stack_addfront(&stack_b, 12);

	// Call the functions and print the state of the stacks after each operation
	ft_printf("Stack A before sa: ");
	print_stack(stack_a);
	sa(stack_a, &ps, 1);
	ft_printf("Stack A after sa: ");
	print_stack(stack_a);

	ft_printf("Stack B before sb: ");
	print_stack(stack_b);
	sb(stack_b, &ps, 1);
	ft_printf("Stack B after sb: ");
	print_stack(stack_b);

	ft_printf("Stack A before ss: ");
	print_stack(stack_a);
	ft_printf("Stack B before ss: ");
	print_stack(stack_b);
	ss(stack_a, stack_b, &ps);
	ft_printf("Stack A after ss: ");
	print_stack(stack_a);
	ft_printf("Stack B after ss: ");
	print_stack(stack_b);

	
	ft_printf("Stack A before pa: ");
	print_stack(stack_a);
	ft_printf("Stack B before pa: ");
	print_stack(stack_b);
	pa(stack_a, stack_b, &ps);
	ft_printf("Stack A after pa: ");
	print_stack(stack_a);
	ft_printf("Stack B after pa: ");
	print_stack(stack_b);

	ft_printf("Stack A before pb: ");
	print_stack(stack_a);
	ft_printf("Stack B before pb: ");
	print_stack(stack_b);
	pb(stack_a, stack_b, &ps);
	ft_printf("Stack A after pb: ");
	print_stack(stack_a);
	ft_printf("Stack B after pb: ");
	print_stack(stack_b);

	ft_printf("Stack A before ra: ");
	print_stack(stack_a);
	ra(&stack_a, &ps, 1);
	ft_printf("Stack A after ra: ");
	print_stack(stack_a);
	
	ft_printf("Stack B before rb: ");
	print_stack(stack_b);
	rb(&stack_b, &ps, 1);
	ft_printf("Stack B after rb: ");
	print_stack(stack_b);

	ft_printf("Stack A before rr: ");
	print_stack(stack_a);
	ft_printf("Stack B before rr: ");
	print_stack(stack_b);
	rr(&stack_a, &stack_b, &ps);
	ft_printf("Stack A after rr: ");
	print_stack(stack_a);
	ft_printf("Stack B after rr: ");
	print_stack(stack_b);
	
	ft_printf("Stack A before rra: ");
	print_stack(stack_a);
	rra(&stack_a, &ps, 1);
	ft_printf("Stack A after rra: ");
	print_stack(stack_a);
	
	ft_printf("Stack B before rrb: ");
	print_stack(stack_b);
	rrb(&stack_b, &ps, 1);
	ft_printf("Stack B after rrb: ");
	print_stack(stack_b);
	
	ft_printf("Stack A before rrr: ");
	print_stack(stack_a);
	ft_printf("Stack B before rrr: ");
	print_stack(stack_b);
	rrr(&stack_a, &stack_b, &ps);
	ft_printf("Stack A after rrr: ");
	print_stack(stack_a);
	ft_printf("Stack B after rrr: ");
	print_stack(stack_b);

	
	return 0;
}
