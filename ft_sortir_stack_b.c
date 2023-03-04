/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortir_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:43:48 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 15:15:59 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_move_ab(t_stack *stack_a, t_stack *stack_b, int move_a, int move_b )
{
	while (move_a < 0)
	{
		ft_reverse_rotate(stack_a);
		ft_printf("rra\n");
		move_a++;
	}
	while (move_b < 0)
	{
		ft_reverse_rotate(stack_b);
		ft_printf("rrb\n");
		move_b++;
	}
	while (move_a > 0)
	{
		ft_rotate(stack_a);
		ft_printf("ra\n");
		move_a--;
	}
	while (move_b > 0)
	{
		ft_rotate(stack_b);
		ft_printf("rb\n");
		move_b--;
	}
}

void	push_ver_a(t_stack *stack_a, t_stack *stack_b, int move_a, int move_b )
{
	while (move_a < 0 && move_b < 0)
	{
		ft_reverse_rotate_ab(stack_a, stack_b);
		ft_printf("rrr\n");
		move_a++;
		move_b++;
	}
	while (move_a > 0 && move_b > 0)
	{
		ft_rotate_ab(stack_a, stack_b);
		ft_printf("rr\n");
		move_a--;
		move_b--;
	}
	ft_move_ab(stack_a, stack_b, move_a, move_b);
}
