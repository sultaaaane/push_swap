/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:32:15 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/08 11:49:06 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	patoi_check(long result)
{
	if (result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

int	ft_patoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 1);
	if (patoi_check(result))
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE), 1);
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

int	is_dup(int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i++])
	{
		j = 1;
		while (tab[j++])
		{
			if (tab[i] == tab[j])
				return (1);
		}
	}
	return (0);
}

int	*push_tab(int *tab, char **str)
{
	char **str1;
	int	i;
	int	j;

	i = 0;
	while (str[i++])
		str1 = ft_split(str," ");
	tab = (int *)malloc(i * sizeof(int));
	if (!tab)
		return (NULL);
	i = 1;
	j = 0;
	while (str1[i++])
		tab[j++] = ft_patoi(str1[i]);
	return (tab);
}
