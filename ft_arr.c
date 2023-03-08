/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:16:15 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/08 20:27:48 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_alloc_arr(t_stack *stack_a, char **spl)
{
	int		i;
	int		count;

	count = lenarr(spl);
	i = 0;
	while (spl[i])
	{
		stack_a->arr[i] = ft_atoi(spl[i]);
		stack_a->len++;
		i++;
	}
	stack_a->arr = ft_dup(stack_a->arr, count);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
}

int	*ft_dup(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
			{
				ft_check_error(1);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	ft_check_num_sortir(t_stack *stack_a)
{
	int	i;
	int	indic;

	i = 0;
	while (i < stack_a->len - 1)
	{
		if (stack_a->arr[i] < stack_a->arr[i + 1])
		{
			indic = 0;
		}
		if (stack_a->arr[i] > stack_a->arr[i + 1])
		{
			indic = 1;
			break ;
		}
		i++;
	}
	if (indic == 0)
		exit(0);
}
