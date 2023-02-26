/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:33:22 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/26 14:27:51 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_count_var(int var , int n , int *count )
{
	if(n > var)
	{
		var = n;
		(*count)++;
	}
	return(*count);
}
int *ft_group(t_stack stack)
{
	int var;
	int i;
	int count;
	int j;
	int *group;

	j = 0;
	group = malloc(sizeof(int) * stack.len);
	while(j < stack.len)
	{
		count = 1;
		var = stack.arr[j];
		i = j;
		while(i < stack.len)
		{
			// if(stack.arr[i] > var)
			// {
			// 	var = stack.arr[i];
			// 	count++;
			// }
			var = ft_count_var( var, stack.arr[i], &count);
			i++;
		}
		i = 0;
		while(i < j)
		{
			// if(stack.arr[i] > var)
			// {
			// 	var = stack.arr[i];
			// 	count++;
			// }
			var = ft_count_var( var, stack.arr[i], &count);
			i++;
		}
		group[j] = count;
		j++;
	}
	return(group);
}
int ft_max (int *group, t_stack stack)
{
	int i ;
	int var;
	int indic;
	
	i = 0;
	indic = 0;
	var = group[i];
	while(i < stack.len)
	{
		if(var < group[i])
		{
			var = group[i];
			indic = i;
		}
		i++;
	}
	free(group);
	return(indic);
}

int *ft_grand_group(t_stack *stackA , int indic ,  int tab_head)
{
	int *tab;
	int i;
	int j;
	int var;

	tab = malloc(sizeof(int)* tab_head);
	i = indic;
	var = stackA->arr[indic];
	j = 1;
	tab[0] = stackA->arr[i];
	while(i < stackA->len)
	{
		if(var <  stackA->arr[i])
		{
			var = stackA->arr[i];
			tab[j++] = var;
		}
		i++;
	}
	i = 0;
	while(i < indic )
	{
		if(var <  stackA->arr[i])
		{
			var = stackA->arr[i];
			tab[j++] = var;
		}
		i++;
	}
	// printf("%d\n", tab_head);
	return(tab);
}
void ft_sortir(t_stack *stackA,t_stack *stackB, int indic ,int *tab)
{
	int i;
	int j;
	int k;

	i = -1;
	while(++i < stackA->len)
	{
		j = 0;
		k = 0;
		while (j < indic)
		{
			if(stackA->arr[i] == tab[j])
			{
				k = 1;
				break;
			}
			j++;
		}
		if (k == 0)
		{
			ft_top_stack(stackA , i ,stackB );
			i =-1;
		}
	}
}

void ft_top_stack(t_stack *stackA , int i, t_stack *stackB)
{
	int indic;

	if(i == 0)
	{
		ft_push_stackA(stackA, stackB);
		ft_printf("pa\n");
		return ;
	}
	if ( i <= stackA->len / 2 )
	{
		while( i > 0)
		{
			ft_rotate(stackA);
			ft_printf("ra\n");
			i--;
		}
		ft_push_stackA(stackA, stackB);
		ft_printf("pa\n");
	}
	else if(i > stackA->len / 2)
	{
		indic = (stackA->len) - i;
		while ( indic > 0)
		{
			ft_reverse_rotate(stackA);
			ft_printf("rra\n");
			indic--;
		}
		ft_push_stackA(stackA, stackB);
		ft_printf("pa\n");
	}
}
