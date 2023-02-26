/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:53:47 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/25 16:08:51 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int *ft_mouvement_stackB(t_stack *stackB)
{
	int i;
	int j;
	int *mvB;
	int len;
	int count;
	int var;

	i = 0;
	j = 0;
	len = stackB->len;
	count = 0;
	mvB = malloc(sizeof(int)* len);
	var = stackB->arr[i];
	while(i < len )
	{
		if ( var == stackB->arr[i] && i <= len / 2)
		{
			mvB[j] = i;
			var = stackB->arr[i + 1];
			j++;
		}
		if ( var == stackB->arr[i] && i > len / 2)
		{
			mvB[j] = (len - i) * (-1);
			var = stackB->arr[i + 1];
			j++;
		}
		i++;
	}
	return(mvB);
}

int *ft_mouvement_stackA(t_stack *stackA , t_stack *stackB)
{
	int *mvA;
	int i;
	int j;

	i = 0;
	j = 0;
	mvA = malloc(sizeof(int)* stackB->len);
	while ( j < stackB->len)
	{
		
		i = 0;
		while (i <stackA->len)
		{
			if(stackB->arr[j] > stackA->arr[i] && stackB->arr[j] < stackA->arr[i + 1])
			{
				if (i <= stackA->len / 2)
					mvA[j] = i + 1;
				else if (i > stackA->len / 2)
					mvA[j] = (stackA->len - (i + 1)) * -1;
				break ;
			}
			else if (stackB->arr[j] < stackA->arr[ft_min_num(stackA)]) {
				mvA[j] = ft_min_num(stackA);
				break ;
			}
			else if (stackB->arr[j] > stackA->arr[ft_max_num(stackA)]) {
				mvA[j] = ft_max_num(stackA);
				break ;
			}
			i++;
		}
		// printf("mva[%d] = %d\n", j, mvA[j]);
		j++;
	}
	return(mvA);
}

int ft_positif_num(int i)
{
	if (i < 0)
	{
		i = i * (-1);
	}
	return(i);
}

int ft_max_num(t_stack *stackA)
{
	int i;
	int var;
	int indic;
	
	i = 0;
	var = stackA->arr[i];
	while(i < stackA->len)
	{
		if(var < stackA->arr[i])
		{
			indic = i;
			var = stackA->arr[i];
		}
		i++;
	}
	return(indic);
}

int *ft_totale_mv(int *mvB, int *mvA ,t_stack *stackB )
{
	int *best_mv;
	int i;

	i = 0;
	best_mv = malloc(sizeof(int)* stackB->len);
	while (i < stackB->len)
	{
		best_mv[i] = ft_positif_num(mvA[i]) + ft_positif_num(mvB[i]);
		i++;
	}
	return(best_mv);
}

int ft_min_mv(int *best_mv , t_stack *stackB)
{
	int i;
	int var; 
	
	i = 0;
	var = best_mv[i];
	while( i < stackB->len -1 && var > best_mv [i + 1])
	{
		var = best_mv[i+1];
		i++;
	}
	return(i);
}

void push_ver_a(t_stack *stackA , t_stack *stackB , int moveA , int moveB )
{
	
	while (moveA < 0 )
	{
		ft_reverse_rotate(stackA);
		ft_printf("rra\n");
		moveA++;
	}
	while (moveA > 0 )
	{
		ft_rotate(stackA);
		ft_printf("ra\n");
		moveA--;
	}
	while (moveB < 0 )
	{
		ft_reverse_rotate(stackB);
		ft_printf("rrb\n");
		moveB++;
	}
	while (moveB > 0 )
	{
		ft_rotate(stackB);
		ft_printf("rb\n");
		moveB--;
	}
	while (moveA < 0 && moveB < 0)
	{
		ft_reverse_rotate_AB(stackA,stackB);
		ft_printf("rrr\n");
		moveA++;
		moveB++;
	}
		while (moveA > 0 && moveB > 0)
	{
		ft_rotate_AB(stackA,stackB);
		ft_printf("rr\n");
		moveA--;
		moveB--;
	}
}
void sortir_stackB(t_stack *stackA , t_stack *stackB , int indic )
{
	int *best_mvA;
	int *best_mvB;
	int moveA;
	int moveB;
	
	best_mvA = ft_mouvement_stackA( stackA , stackB);
	best_mvB = ft_mouvement_stackB(stackB);
	moveA = best_mvA[indic];
	moveB = best_mvB[indic];
	push_ver_a(stackA , stackB , moveA , moveB);
	ft_push_stackA(stackB , stackA);
	ft_printf("pb\n");
	
}

int best_mouvement(t_stack *stackA , t_stack *stackB)
{
	int *tab;
	int min_num;
	while(stackB->len != 0)
	{
		tab = ft_totale_mv( ft_mouvement_stackA( stackA , stackB), ft_mouvement_stackB(stackB) , stackB );
		min_num = ft_min_mv(tab , stackB);
		sortir_stackB(stackA , stackB , min_num);
		
	}
	return (min_num);
}
int ft_min_num(t_stack *stackA)
{
	int i;
	int var;
	int indic;
	
	i = 0;
	var = stackA->arr[i];
	while(i < stackA->len)
	{
		if(var > stackA->arr[i])
		{
			indic = i;
			var = stackA->arr[i];
		}
		i++;
	}
	return(indic);
}
void ft_top_num(t_stack *stackA )
{
	int i;
	int indic;
	
	i = 0;
	indic = ft_min_num(stackA);
	if (indic <= stackA->len / 2)
	{
		while(i < indic)
		{
			ft_rotate(stackA);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		while(indic < stackA->len )
		{
			ft_reverse_rotate(stackA);
			ft_printf("rra\n");
			indic++;
		}
	}
}