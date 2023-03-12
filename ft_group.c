/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:33:22 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/12 15:54:10 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_count_var(int j, t_stack *stack, int count, int var)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (stack->arr[i] > var)
		{
			var = stack->arr[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	*ft_group(t_stack *stack)
{
	int	var;
	int	i;
	int	count;
	int	j;
	int	*group;

	j = -1;
	group = malloc(sizeof(int) * stack->len);
	while (++j < stack->len)
	{
		i = j;
		count = 1;
		var = stack->arr[j];
		while (i < stack->len)
		{
			if (stack->arr[i] > var)
			{
				var = stack->arr[i];
				count++;
			}
			i++;
		}
		group[j] = ft_count_var(j, stack, count, var);
	}
	return (group);
}

int	ft_max(int *group, t_stack *stack)
{
	int	i;
	int	var;
	int	indic;

	i = 0;
	indic = 0;
	var = group[i];
	while (i < stack->len)
	{
		if (var < group[i])
		{
			var = group[i];
			indic = i;
		}
		i++;
	}
	return (indic);
}

int	*ft_tab(t_stack *stack_a, int indic, int *tab, int j)
{
	int	i;
	int	var;

	var = tab[j - 1];
	i = -1;
	while (++i < indic)
	{
		if (var < stack_a->arr[i])
		{
			var = stack_a->arr[i];
			tab[j++] = var;
		}
	}
	return (tab);
}

int	*ft_grand_group(t_stack *stack_a, int indic, int size)
{
	int	*tab;
	int	i;
	int	j;
	int	var;

	tab = malloc(sizeof(int) * size);
	var = stack_a->arr[indic];
	j = 1;
	tab[0] = var;
	i = indic - 1;
	while (++i < stack_a->len)
	{
		if (var < stack_a->arr[i])
		{
			var = stack_a->arr[i];
			tab[j++] = var;
		}
	}
	return (ft_tab(stack_a, indic, tab, j));
}
