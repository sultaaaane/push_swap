/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:32 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/25 01:52:51 by mbentahi         ###   ########.fr       */
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

void pa(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void ss(t_stack *stack_a,t_stack *stack_b,t_pushswap *ps);
void sb(t_stack *stack,t_pushswap *ps,int flag);
void sa(t_stack *stack,t_pushswap *ps,int flag);
void pb(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void ra(t_stack **stack,t_pushswap *ps,int flag);
void rb(t_stack **stack,t_pushswap *ps,int flag);
void rr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void rra(t_stack **stack,t_pushswap *ps,int flag);
int smallest_value(t_stack *stack);
void sort_3(t_stack **stack,t_pushswap *ps);
void sort_2(t_stack **stack_a,t_pushswap *ps);
void rrr(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
void rrb(t_stack **stack,t_pushswap *ps,int flag);
int *push_array(t_stack *stack_a);
void sort_5(t_stack **stack_a,t_stack **stack_b,t_pushswap *ps);
int stack_size(t_stack *stack);
int indexing(t_stack *stack,int value);
int biggest_value(t_stack *stack);
void free_stack(t_stack **stack);
void sort_all(t_stack **stack_a, t_stack **stack_b,t_pushswap *ps);
void	sort_helper(t_stack *stack, int *size, int *p);
int find_index(t_stack *stack,int index,int p);
void	ft_push_to_a(t_stack **stack_a, t_stack **stack_b, t_pushswap *ps);
void array_indexing(t_stack *stack_a,int *tab);
void sort_array(int *tab,int size);
int	find_position(t_stack *stack, int value);
int	find_highest(t_stack *stack);
int	is_dup(t_stack *stack);
int is_whitespace(char *str);
void ft_free2d(char **str);
int is_num(char *str);
void  check_parse(int ac, char **av);
void push_to_stack(t_stack **stack, int ac, char **av);
int	arg_char(char *str);
long	ft_patoi(const char *str);
long	patoi_check(long result);
int is_empty(t_stack *stack);
int is_sorted(t_stack *stack);
t_stack *pop(t_stack **stack);
void stack_addback(t_stack **stack,t_stack *new_s);
t_stack *stack_last(t_stack *stack);
void stack_addfront(t_stack **stack,t_stack *new_s);
t_stack *stack_new(int value);
void print_stack(t_stack *stack);
int stack_size(t_stack *stack);
void free_stack(t_stack **stack);
void sort_all(t_stack **stack_a, t_stack **stack_b,t_pushswap *ps);

#endif