/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:03:16 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/11 11:30:44 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;	
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}	
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	if (res > 2147483647 || res < -2147483648 )
		ft_check_error(1);
	if (str[i] != '\0')
		ft_check_error(1);
	return (res * sign);
}
