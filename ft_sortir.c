/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:39:47 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 12:25:55 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sortir(t_stack *stack_a, t_stack *stack_b, int size, int *tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack_a->len)
	{
		j = 0;
		k = 0;
		while (j < size)
		{
			if (stack_a->arr[i] == tab[j])
			{
				k = 1;
				break ;
			}
			j++;
		}
		if (k == 0)
		{
			ft_top_stack(stack_a, i, stack_b);
			i = -1;
		}
		i++;
	}
}

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_stack_a(stack_a, stack_b);
	ft_printf("pb\n");
	return ;
}

void	ft_push_len(t_stack *stack_a, t_stack *stack_b, int indic)
{
	(void)stack_b;
	while (indic > 0)
	{
		ft_reverse_rotate(stack_a);
		ft_printf("rra\n");
		indic--;
	}
}

void	ft_top_stack(t_stack *stack_a, int i, t_stack *stack_b)
{
	int	indic;

	if (i < stack_a->len / 2)
	{
		while (i > 0)
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
			i--;
		}
	}
	else if (i >= stack_a->len / 2)
	{
		indic = (stack_a->len) - i;
		ft_push_len(stack_a, stack_b, indic);
	}
	ft_push_stack_a(stack_a, stack_b);
	ft_printf("pb\n");
}
