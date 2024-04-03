/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:32:15 by mbentahi          #+#    #+#             */
/*   Updated: 2024/04/02 23:18:21 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	patoi_check(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

long	ft_patoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == ' ' || str[i] == '\0')
			return (2147483648);
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (patoi_check(result))
		return (2147483648);
	if (check_overflow(str))
		return (2147483648);
	return (result * sign);
}

int	arg_char(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	return (0);
}

int	is_dup(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack;
	if (!temp)
		return (0);
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}
