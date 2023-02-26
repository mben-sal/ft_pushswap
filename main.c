/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:23:16 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/26 12:00:44 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenArr(char **spl) 
{
	int	len = 0;
	while (spl[len])
		len++;
	return (len);
}

void    init_stack(t_stack *mystack, int size)
{
    mystack->len = 0;
    mystack->arr = malloc(sizeof(int) * size);
}

void ft_check_error(int ac)
{
	if (ac == 1)
	{
		ft_printf ("error\n");
		exit(1);
	}
	if(ac == 2)
	{
		ft_printf("error\n");
		exit(1);
	}
}
void ft_check_num_sortir(t_stack *stackA)
{
	int i;
	int indic;
	
	i = 0;
	while (i < stackA->len - 1 )
	{
		if(stackA->arr[i] < stackA->arr[i+1])
		{
			indic = 0;
		}
		if (stackA->arr[i] > stackA->arr[i+1])
		{
			indic = 1;
			break;
		}
		i++;
	}
	if (indic == 0)	
		exit(0);
}
int main (int ac , char **av)
{
	t_stack stackA;
	t_stack stackB;
	int indic;
	char	**spl;
	int max_group;
	int *group;
	int *grand_group;
	int i;

	if (ac == 1 || ac == 2)
		ft_check_error(ac);
	spl = ft_alloc_str(av);
	init_stack(&stackA, lenArr(spl));
	ft_alloc_arr(&stackA, spl);
	ft_check_num_sortir(&stackA); 
	if( stackA.len <= 5 )
		ft_cinq_num(&stackA);
	group = ft_group(stackA);
	max_group = ft_max(group, stackA);
	indic = group[max_group];
	grand_group = ft_grand_group(&stackA, max_group, indic);
	init_stack(&stackB, lenArr(spl));
	ft_sortir(&stackA,&stackB,indic,grand_group);
	best_mouvement(&stackA , &stackB);
	ft_top_num(&stackA);
			i = -1;
	while (++i < stackA.len)
		printf("stackA[%d] = %d\n", i, stackA.arr[i]);

}
