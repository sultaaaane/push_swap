/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:48:32 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/15 02:56:23 by mbentahi         ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node		*top;
}					t_stack;

typedef struct s_pushswap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int *tab;
	int				size_a;
	int				size_b;
	int				argc;
	char			**argv;
}					t_pushswap;

long ft_patoi(const char *str);
long patoi_check(long result);
int arg_char(char *str);
int is_dup(int *tab);
void initializer(t_stack *stack);
int isempty(t_stack *stack);
void push(t_stack *stack,int value);
int pop(t_stack *stack);
void print_stack(t_stack *stack);
void pa(t_stack *stack_a,t_stack *stack_b);
void  check_parse(int ac, char **av);
void ft_free2d(char **str);



#endif