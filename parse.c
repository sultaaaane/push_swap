/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:32:15 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/24 21:07:24 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	patoi_check(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

long	ft_patoi(const char *str)
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
			ft_printf("Error");
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
				ft_printf("Error\n");
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
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_parse(int ac, char **av)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < ac && av[i])
	{
		if (is_whitespace(av[i]) || av[i][0] == '\0')
			return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
		{
			if (ft_patoi(temp[j]) > INT_MAX || is_num(temp[j]))
			{
				write(2, "Error\n", 6);
				ft_free2d(temp);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		ft_free2d(temp);
	}
}

void	push_to_stack(t_stack **stack, int ac, char **av)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
		{
			stack_addback(stack, stack_new(ft_patoi(temp[j])));
			j++;
		}
		i++;
		ft_free2d(temp);
	}
}
