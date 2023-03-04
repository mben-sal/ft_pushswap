/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvement_stack_a_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:19:24 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 21:33:49 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_mouvement_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	*mv_a;
	int	i;
	int	j;
	int	indic;

	i = 0;
	j = -1;
	mv_a = malloc(sizeof(int) * stack_b->len);
	indic = ft_min_num(stack_a);
	while (++j < stack_b->len)
	{
		i = indic;
		while (i < stack_a->len && stack_b->arr[j] > stack_a->arr[i])
			i++;
		if (i == stack_a->len && stack_b->arr[j] > stack_a->arr[0])
		{
			i = 0;
			while (i < indic && stack_a->arr[i] < stack_b->arr[j])
				i++;
		}
		mv_a[j] = i;
		if (mv_a[j] > stack_a->len / 2)
			mv_a[j] = (stack_a->len - i) * -1;
	}
	return (mv_a);
}

int	*ft_mouvement_stack_b(t_stack *stack_b)
{
	int	i;
	int	j;
	int	*mv_b;
	int	len;
	int	var;

	i = -1;
	j = 0;
	len = stack_b->len;
	mv_b = malloc (sizeof(int) * len);
	while (++i < len)
	{
		var = stack_b->arr[i];
		if (var == stack_b->arr[i] && i <= len / 2)
		{
			mv_b[j++] = i;
			var = stack_b->arr[i + 1];
		}
		if (var == stack_b->arr[i] && i > len / 2)
		{
			mv_b[j++] = (len - i) * (-1);
			var = stack_b->arr[i + 1];
		}
	}
	return (mv_b);
}

int	best_mouvement(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab;
	int	*mv_a;
	int	*mv_b;
	int	move_a;
	int	move_b;

	while (stack_b->len != 0)
	{
		mv_a = ft_mouvement_stack_a(stack_a, stack_b);
		mv_b = ft_mouvement_stack_b(stack_b);
		tab = ft_totale_mv(mv_a, mv_b, stack_b);
		move_a = mv_a[ft_min_mv(tab, stack_b)];
		move_b = mv_b[ft_min_mv(tab, stack_b)];
		push_ver_a(stack_a, stack_b, move_a, move_b);
		ft_push_stack_a(stack_b, stack_a);
		ft_printf("pa\n");
		free(mv_a);
		free(mv_b);
	}
	return (ft_min_mv(tab, stack_b));
}

int	*ft_totale_mv(int *mv_b, int *mv_a, t_stack *stack_b)
{
	int		*best_mv;
	int		i;

	i = 0;
	best_mv = malloc(sizeof(int) * stack_b->len);
	while (i < stack_b->len)
	{
		best_mv[i] = ft_positif_num(mv_a[i]) + ft_positif_num(mv_b[i]);
		i++;
	}
	return (best_mv);
}

int	ft_positif_num(int i)
{
	if (i < 0)
	{
		i = i * (-1);
	}
	return (i);
}
