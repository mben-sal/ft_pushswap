/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:32:53 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/22 18:06:58 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s1)
{
	int	i;
	int	len;
	char	*ptr;
	char	*str;

	i = 0;
	str = (char *)s1;
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) *(len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
