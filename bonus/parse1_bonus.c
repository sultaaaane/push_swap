/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:26:58 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/29 11:19:04 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int isallwhitespace(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}