/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:51:12 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/01 21:10:09 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *stack)
{
	int		len;

	len = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = len;
}

void	ft_rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = stack->arr[0];
	while (i < stack->len)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->len - 1] = tmp;
}

void	ft_reverse_rotate(t_stack *stack)
{
	int		tmp;
	int		i;

	i = stack->len - 1;
	tmp = stack->arr[i];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
}

void	ft_push_stack_a(t_stack *first, t_stack *last)
{
	int		i;
	int		count;

	i = 0;
	if (!first->len)
		return ;
	last->len++;
	count = last->len;
	while (count > i)
	{
		last->arr[count] = last->arr[count - 1];
		count--;
	}
	last->arr[0] = first->arr[0];
	while (i < first->len)
	{
		first->arr[i] = first->arr[i + 1];
		i++;
	}
	first->len--;
}
