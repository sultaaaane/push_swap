/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:47:55 by mbentahi          #+#    #+#             */
/*   Updated: 2024/03/31 14:49:14 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int check_instructions(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 's' && str[i] != 'p' && str[i] != 'r')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
