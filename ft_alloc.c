/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:02:40 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/20 20:20:50 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_alloc_str(char **av)
{
	int i;
	int count;
	char *str;
	char **spl;

	i = 1;
	count = 0;
	while(av[i])
	{
		if (av[i][0] == '\0')
			ft_check_error(1);
		count += ft_strlen(av[i]);
		i++;
	}
	str = malloc(sizeof(char)*(count));
	i = 1;
	str = NULL;
	while(av[i])
	{
		str = ft_strjoin(av[i], " ", str);
		i++;
	}
	spl = ft_split(str, ' ');
	free (str);
	return(spl);
}