/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:52:29 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/26 14:27:01 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdarg.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<string.h>
# include <sys/errno.h>
# include <errno.h>

typedef struct s_spl
{
	int	i;
	int	j;
	int	len;
	int		index;
	int		count;
	char	**ptr;
}	t_spl;

typedef struct s_stack
{
	int		*arr;
	int	len;
}	t_stack;

int	ft_isdigit(int arg);
int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int main (int ac , char **av);
int	ft_strlen(const char *str);
int	ft_strncmp(const char *first, const char *second, int len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, char const *s3);
int	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	**ft_alloc_str(char **av);
void	ft_alloc_arr(t_stack *stack_a, char **spl);
int *ft_dup(int *arr ,int count);
int	lenArr(char **spl);
void	**ft_free(char **s);
void ft_check_error(int ac);
void ft_swap(t_stack *stack);
void ft_push_stackA(t_stack *first, t_stack *last);
int *ft_group(t_stack stack);
int ft_max(int *group, t_stack stack);
void ft_sortir(t_stack *stackA,t_stack *stackB, int indic ,int *tab);
void ft_rotate(t_stack *stack);
int *ft_grand_group(t_stack *stackA , int indic ,  int tab_head);
void ft_top_stack(t_stack *stackA , int i, t_stack *stackB);
void ft_reverse_rotate(t_stack *stack);
void ft_push(t_stack stackA, t_stack stackB);
int *ft_mouvement_stackB(t_stack *stackB);
int *ft_mouvement_stackA(t_stack *stackA , t_stack *stackB);
int *ft_totale_mv(int *mvB, int *mvA ,t_stack *stackB );
int ft_min_mv(int *best_mv , t_stack *stackB);
int ft_positif_num(int i);
int best_mouvement(t_stack *stackA , t_stack *stackB);
void sortir_stackB(t_stack *stackA , t_stack *stackB , int indic );
void push_ver_a(t_stack *stackA , t_stack *stackB , int moveA , int moveB );
void ft_reverse_rotate_AB(t_stack *stackA , t_stack *stackB);
void ft_rotate_AB(t_stack *stackA , t_stack *stackB);
int ft_min_num(t_stack *stackA);
void ft_top_num(t_stack *stackA );
int ft_max_num(t_stack *stackA);
void ft_cinq_num(t_stack *stackA);
void ft_check_num_sortir(t_stack *stackA);
void ft_trois_num(t_stack *stackA);
void ft_deux_num(t_stack *stackA);
int ft_count_var(int var , int n , int *count );

#endif