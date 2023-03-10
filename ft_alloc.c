/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:02:40 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/10 20:59:17 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_alloc_str(char **av)
{
	int		i;
	int		count;
	char	*str;
	char	**spl;

	i = 1;
	count = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			ft_check_error(1);
		count += ft_strlen(av[i]);
		i++;
	}
	str = NULL;
	i = 1;
	while (av[i])
	{
		str = ft_strjoin(av[i], " ", str);
		i++;
	}
	spl = ft_split (str, ' ');
	free(str);
	return (spl);
}

void	ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}

void	ft_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_check_error(int ac)
{
	if (ac == 1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}
