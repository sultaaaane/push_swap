/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:19 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/22 21:21:10 by mbentahi         ###   ########.fr       */
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
	if (flag)
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
	if (flag)
		ft_printf("sb\n");
}

void ss(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps)
{
	sa(stack_a,ps,0);
	sb(stack_b,ps,0);
	ft_printf("ss\n");
}

void pa(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	if (ps->size_b == 0)
		return ;
	stack_addfront(stack_a,pop(stack_b));
	ps->size_a++;
	ps->size_b--;
	ft_printf("pa\n");
}

void pb(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	if (ps->size_a == 0)
		return ;
	stack_addfront(stack_b,pop(stack_a));
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
	if (flag)
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
	if (flag)
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
	t_stack *last;
    t_stack *second_last;
	
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
        ft_printf("rra\n");
}

void rrb(t_stack **stack,t_pushswap *ps,int flag)
{
	t_stack *last;
    t_stack *second_last;
	
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
        ft_printf("rrb\n");
}

void rrr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	rra(stack_a,ps,0);
	rrb(stack_b,ps,0);
	ft_printf("rrr\n");
}

void sort_2(t_stack **stack_a,t_pushswap *ps)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a,ps,1);
}

void sort_3(t_stack **stack,t_pushswap *ps)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack,ps,1);
	if ((*stack)->next->value > stack_last(*stack)->value)
		sa((*stack)->next,ps,1);
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack,ps,1);
}

int smallest_value(t_stack *stack)
{
	t_stack *temp;
	int min;
	
	temp = stack;
	min = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

int biggest_value(t_stack *stack)
{
	t_stack *temp;
	int max;
	
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

int indexing(t_stack *stack,int value)
{
	t_stack *temp;
	int index;
	
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



int stack_size(t_stack *stack)
{
	int size;
	t_stack *temp;
	
	size = 0;
	temp = stack;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void sort_5(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	int smallest;
	int index;

	while (stack_size(*stack_a) > 3)
	{
		smallest = smallest_value(*stack_a);
		index = indexing(*stack_a,smallest);
		if (index <= stack_size(*stack_a) / 2 && index != 0)
			ra(stack_a,ps,1);
		else if (index >= stack_size(*stack_a) / 2 && index != 0)
			rra(stack_a,ps,1);
		else
			pb(stack_a,stack_b,ps);			
	}
	sort_3(stack_a,ps);
	while (!is_empty(*stack_b))
		pa(stack_a,stack_b,ps);
}

int *push_array(t_stack *stack_a)
{
	int *tab;
	int i;

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

void array_indexing(t_stack *stack_a,int *tab)
{
	t_stack *temp;
	int i;
	int j;
	
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

void sort_array(int *tab,int size)
{
	int i;
	int j;
	int holder;

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

void push_a(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps)
{
	int index;
	int highest;

	highest = biggest_value(*stack_b);
	index = indexing(*stack_b,highest);
	print_stack(*stack_a);
	print_stack(*stack_b);
	while (stack_size(*stack_b) > 0)
	{
		if (highest == (*stack_b)->value)
		{
				pa(stack_a,stack_b,ps);
			if (stack_size(*stack_b) > 0)
			{
				highest = biggest_value(*stack_b);
				index = indexing(*stack_b,highest);
			}
		}
		else if (index <= stack_size(*stack_b) / 2 && highest != (*stack_b)->value)
				rb(stack_b,ps,1);
		else
			rrb(stack_a,ps,1);
		}
}

int find_index(t_stack *stack,int index,int p)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index <= index || stack->index <= index + p)
			break;
		stack = stack->next;
		i++;
	}
	return (i);
}

void sort_all(t_stack **stack_a, t_stack **stack_b,t_pushswap *ps)
{
	int i;
	int p;
	int *tab;
	
	tab = push_array(*stack_a);
	sort_array(tab,stack_size(*stack_a));
	array_indexing(*stack_a,tab);
	i = 0;
	p = 15;
	while (i < stack_size(*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a,stack_b,ps);
			rb(stack_b,ps,1);
			i++;
		}
		else if ((*stack_a)->index <= i + p)
		{
			pb(stack_a,stack_b,ps);
			i++;
		}
		else if (find_index(*stack_a,i,p) < stack_size(*stack_a) / 2)
			ra(stack_a,ps,1);
		else
			rra(stack_a,ps,1);
	}
	push_a(stack_a,stack_b,ps);
}


void free_stack(t_stack **stack) {
	t_stack *temp;
	while (*stack != NULL) {
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int main() {
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_pushswap ps;

	// Initialize the pushswap struct and the stacks
	ps.size_a = 5;
	ps.size_b = 0;
	stack_a = NULL;
	stack_b = NULL;

	// Push 6 numbers to stack_a
	stack_addfront(&stack_a, stack_new(1));
	stack_addfront(&stack_a, stack_new(2));
	stack_addfront(&stack_a, stack_new(3));
	stack_addfront(&stack_a, stack_new(4));
	stack_addfront(&stack_a, stack_new(7));
	// stack_addfront(&stack_a, stack_new(6));
	
	// Push 6 numbers to stack_b
	// stack_addfront(&stack_b, stack_new(7));
	// stack_addfront(&stack_b, stack_new(8));
	// stack_addfront(&stack_b, stack_new(9));
	// stack_addfront(&stack_b, stack_new(10));
	// stack_addfront(&stack_b, stack_new(11));
	// stack_addfront(&stack_b, stack_new(12));
	
	// Call the functions and print the state of the stacks after each operation
	
	ft_printf("Stack A before sa: ");
	print_stack(stack_a);
	sort_all(&stack_a, &stack_b, &ps);
	ft_printf("Stack A after sa: ");
	print_stack(stack_a);
	

	free_stack(&stack_a);
	free_stack(&stack_b);
	
	return 0;
}
