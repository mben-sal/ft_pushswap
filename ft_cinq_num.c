/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cinq_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:40:43 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/01 20:30:00 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_cinq_quatre(int indic, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (indic < stack_a->len / 2)
	{
		while (i < indic)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
			i++;
		}
		ft_push_stack_a(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
	{
		while (indic < stack_a->len)
		{
			ft_reverse_rotate(stack_a);
			ft_printf("rra\n");
			indic++;
		}
		ft_push_stack_a(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	ft_cinq_and_quatre(t_stack *stack_a, t_stack *stack_b)
{
	int		j;
	int		indic;

	j = 0;
	while (j < 2)
	{
		indic = ft_min_num(stack_a);
		ft_cinq_quatre(indic, stack_a, stack_b);
		j++;
	}
}

void	ft_cinq_num(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		len;

	len = stack_a->len;
	i = 0;
	if (len == 2 && stack_a->arr[i] > stack_a->arr[i + 1])
		ft_deux_num(stack_a);
	if (len <= 5)
	{
		if (len == 3)
		{
			ft_trois_num(stack_a);
			exit(1);
		}
		if (len > 3)
		{
			ft_cinq_and_quatre(stack_a, stack_b);
			ft_trois_num(stack_a);
		}
	}
}

void	ft_deux_num(t_stack *stack_a)
{
	if (stack_a->len == 1)
		exit(0);
	if (stack_a->len == 2 && stack_a->arr[0] > stack_a->arr[1])
	{
		ft_swap(stack_a);
		ft_printf("sa\n");
	}
}

void	ft_trois_num(t_stack *stack_a)
{
	if (stack_a->arr[0] < stack_a->arr[1] && stack_a->arr[1] > stack_a->arr[2])
	{
		ft_reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	if (stack_a->arr[0] > stack_a->arr[1] && stack_a->arr[0] > stack_a->arr[2])
	{
		ft_rotate(stack_a);
		ft_printf("ra\n");
	}
	if (stack_a->arr[0] > stack_a->arr[1] && stack_a->arr[0] < stack_a->arr[2])
	{
		ft_swap(stack_a);
		ft_printf("sa\n");
	}
}
