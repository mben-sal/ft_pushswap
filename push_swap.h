/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:52:29 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/12 17:26:53 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	int		i;
	int		j;
	int		len;
	int		index;
	int		count;
	char	**ptr;
}	t_spl;

typedef struct s_stack
{
	int	*arr;
	int	len;
}	t_stack;

int		ft_isdigit(int arg);
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		main(int ac, char **av);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *first, const char *second, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2, char *s3);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	**ft_alloc_str(char **av);
void	ft_alloc_arr(t_stack *stack_a, char **spl);
int		*ft_dup(int *arr, int count);
int		lenarr(char **spl);
void	ft_free(char **s);
void	ft_check_error(int ac);
void	ft_swap(t_stack *stack);
void	ft_push_stack_a(t_stack *first, t_stack *last);
int		*ft_group(t_stack *stack);
int		ft_max(int *group, t_stack *stack);
void	ft_sortir(t_stack *stack_a, t_stack *stack_b, int indic, int *tab);
void	ft_rotate(t_stack *stack);
int		*ft_grand_group(t_stack *stack_a, int indic, int tab_head);
void	ft_top_stack(t_stack *stack_a, int i, t_stack *stack_b);
void	ft_reverse_rotate(t_stack *stack);
void	ft_push(t_stack stack_a, t_stack stack_b);
int		*ft_mouvement_stack_b(t_stack *stack_b);
int		*ft_mouvement_stack_a(t_stack *stack_a, t_stack *stack_b);
int		*ft_totale_mv(int *mv_b, int *mv_a, t_stack *stack_b );
int		ft_min_mv(int *best_mv, t_stack *stack_b);
int		ft_positif_num(int i);
void	best_mouvement(t_stack *stack_a, t_stack *stack_b);
void	sortir_stack_b(t_stack *stack_a, t_stack *stack_b, int indic);
void	push_ver_a(t_stack *stack_a, t_stack *stack_b, int move_a, int move_b );
void	ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_ab(t_stack *stack_a, t_stack *stack_b);
int		ft_min_num(t_stack *stack_a);
void	ft_top_num(t_stack *stack_a);
int		ft_max_num(t_stack *stack_a);
void	ft_cinq_num(t_stack *stack_a, t_stack *stack_b);
void	ft_check_num_sortir(t_stack *stack_a);
void	ft_trois_num(t_stack *stack_a);
void	ft_deux_num(t_stack *stack_a);
void	ft_cinq_and_quatre(t_stack *stack_a, t_stack *stack_b);
void	ft_check_max(long res, int sign);
char	*ft_alloc_ptr(char const *s1, char const *s2, char const *s3);
void	ft_traite_cinq_num(t_stack *stack_a, t_stack *stack_b);
int		lenarr(char **spl);
int		ft_count_var(int j, t_stack *stack, int count, int var);
void	ft_cinq_quatre(int indic, t_stack *stack_a, t_stack *stack_b);
void	ft_move_ab(t_stack *stack_a, t_stack *stack_b, int move_a, int move_b );
void	ft_push_len(t_stack *stack_a, t_stack *stack_b, int indic);
void	ft_putstr(char *s);
char	*ft_strnjoin(char *s1, char *s2);
int		ft_strnlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strndup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);

#endif