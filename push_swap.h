/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:32 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/23 01:53:17 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int 			index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_pushswap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int *tab;
	int				size_a;
	int				size_b;
}					t_pushswap;

long ft_patoi(const char *str);
long patoi_check(long result);
int arg_char(char *str);
int	is_dup(t_stack *stack);
void initializer(t_stack *stack);
int isempty(t_stack *stack);
t_stack *pop(t_stack **stack);
void print_stack(t_stack *stack);
void  check_parse(int ac, char **av);
void ft_free2d(char **str);
t_stack *stack_new(int value);
void stack_addfront(t_stack **stack,t_stack *new_s);
t_stack *stack_last(t_stack *stack);
void stack_addback(t_stack **stack,t_stack *new_s);
void sa(t_stack *stack,t_pushswap *ps,int flag);
void sb(t_stack *stack,t_pushswap *ps,int flag);
void ss(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps);
void pa(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void pb(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void ra(t_stack **stack,t_pushswap *ps,int flag);
void rb(t_stack **stack,t_pushswap *ps,int flag);
void rr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void rra(t_stack **stack,t_pushswap *ps,int flag);
void rrb(t_stack **stack,t_pushswap *ps,int flag);
void rrr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void free_stack(t_stack **stack);
void sort_5(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
int stack_size(t_stack *stack);
int biggest_value(t_stack *stack);
int indexing(t_stack *stack,int value);
int smallest_value(t_stack *stack);
void sort_3(t_stack **stack,t_pushswap *ps);
void sort_2(t_stack **stack_a,t_pushswap *ps);
int is_empty(t_stack *stack);
int is_sorted(t_stack *stack);
void push_to_stack(t_stack **stack, int ac, char **av);


#endif