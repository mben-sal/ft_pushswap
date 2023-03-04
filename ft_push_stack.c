/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:47 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 12:26:37 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_min_num(t_stack *stack_a)
{
	int	i;
	int	var;
	int	indic;

	i = 0;
	var = stack_a->arr[i];
	while (i < stack_a->len)
	{
		if (var >= stack_a->arr[i])
		{
			indic = i;
			var = stack_a->arr[i];
		}
		i++;
	}
	return (indic);
}

int	ft_max_num(t_stack *stack_a)
{
	int	i;
	int	var;
	int	indic;

	i = 0;
	var = stack_a->arr[i];
	while (i < stack_a->len)
	{
		if (var < stack_a->arr[i])
		{
			indic = i;
			var = stack_a->arr[i];
		}
		i++;
	}
	return (indic);
}

int	ft_min_mv(int *best_mv, t_stack *stack_b)
{
	int	i;
	int	var;
	int	indic;

	i = 0;
	indic = 0;
	var = best_mv[i];
	while (i < stack_b->len)
	{
		if (var >= best_mv[i])
		{
			indic = i;
			var = best_mv[i];
		}
		i++;
	}
	return (indic);
}

void	ft_top_num(t_stack *stack_a )
{
	int	i;
	int	indic;

	i = 0;
	indic = ft_min_num(stack_a);
	if (indic <= stack_a->len / 2)
	{
		while (i < indic)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		while (indic < stack_a->len)
		{
			ft_reverse_rotate(stack_a);
			ft_printf("rra\n");
			indic++;
		}
	}
}
