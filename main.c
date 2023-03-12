/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:23:16 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/12 12:19:51 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenarr(char **spl)
{
	int	len;

	len = 0;
	while (spl[len])
		len++;
	return (len);
}

void	init_stack(t_stack *stack, int size)
{
	stack->len = 0;
	stack->arr = malloc(sizeof(int) * size);
}

void	ft_traite_cinq_num(t_stack *stack_a, t_stack *stack_b)
{
	init_stack(stack_b, 2);
	ft_cinq_num(stack_a, stack_b);
	while (stack_b->len != 0)
	{
		ft_push_stack_a(stack_b, stack_a);
		ft_printf("pa\n");
	}
	free(stack_a->arr);
	free(stack_b->arr);
	exit(0);
}

void	ft_push_swap(char **spl)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*group;
	int		*grand_group;
	int		size;

	init_stack(&stack_a, lenarr(spl));
	ft_alloc_arr(&stack_a, spl);
	ft_check_num_sortir(&stack_a);
	if (stack_a.len <= 5)
	{
		ft_traite_cinq_num(&stack_a, &stack_b);
	}
	group = ft_group(&stack_a);
	size = group[ft_max(group, &stack_a)];
	init_stack(&stack_b, lenarr(spl));
	grand_group = ft_grand_group(&stack_a, ft_max(group, &stack_a), size);
	ft_sortir(&stack_a, &stack_b, size, grand_group);
	best_mouvement(&stack_a, &stack_b);
	ft_top_num(&stack_a);
	ft_free(spl);
	free(group);
	free(grand_group);
	free(stack_a.arr);
	free(stack_b.arr);
}

int	main(int ac, char **av)
{
	char	**spl;

	spl = NULL;
	if (ac == 1)
		exit(0);
	spl = ft_alloc_str(av);
	ft_push_swap(spl);
}
