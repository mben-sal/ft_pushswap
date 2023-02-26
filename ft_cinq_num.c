/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cinq_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:40:43 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/26 11:59:31 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_cinq_num(t_stack *stackA)
{
	int i;
	int len;
	
	len = stackA->len;
	i = 0;
	
	if(len == 2 && stackA->arr[i] > stackA->arr[i+1])
		ft_deux_num(stackA);
	if(len <= 5)
	{
		
		if(len == 3)
		{
			ft_trois_num(stackA);
			exit(1);
		}
		if(len > 3)
			ft_top_num(stackA);
	}
}

void ft_deux_num(t_stack *stackA)
{
	if(stackA->len == 1)
		exit(0);
	if(stackA->len == 2 && stackA->arr[0] > stackA->arr[1])
	{
		ft_swap(stackA);
		ft_printf("sa\n");
	}
}

void ft_trois_num(t_stack *stackA)
{
	if(stackA->arr[0] < stackA->arr[1] && stackA->arr[1] > stackA->arr[2])
	{
		ft_reverse_rotate(stackA);
		ft_printf("rra\n");
	}
	if(stackA->arr[0] > stackA->arr[1] && stackA->arr[0] > stackA->arr[2])
	{
		ft_rotate(stackA);
		ft_printf("ra\n");
	}
	if(stackA->arr[0]> stackA->arr[1] && stackA->arr[0] < stackA->arr[2])
	{
		ft_swap(stackA);
		ft_printf("sa\n");
	}
			
}
