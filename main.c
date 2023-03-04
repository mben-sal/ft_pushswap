/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:23:16 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 21:33:01 by mben-sal         ###   ########.fr       */
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

void	init_stack(t_stack *mystack, int size)
{
	mystack->len = 0;
	mystack->arr = malloc(sizeof(int) * size);
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
		free(&stack_b.arr);
	}
	group = ft_group(&stack_a);
	size = group[ft_max(group, stack_a)];
	init_stack(&stack_b, lenarr(spl));
	grand_group = ft_grand_group(&stack_a, ft_max(group, stack_a), size);
	free(group);
	ft_free(spl);
	ft_sortir(&stack_a, &stack_b, size, grand_group);
	free(grand_group);
	best_mouvement(&stack_a, &stack_b);
	ft_top_num(&stack_a);
	// free(&stack_b.arr);
}

int	main(int ac, char **av)
{
	char	**spl;

	if (ac <= 1)
		ft_check_error(1);
	spl = ft_alloc_str(av);
	ft_push_swap(spl);
	// while (1) {}
}
