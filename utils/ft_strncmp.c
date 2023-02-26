/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:03:32 by mben-sal          #+#    #+#             */
/*   Updated: 2023/02/22 18:06:58 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

int	ft_strncmp(const char *first, const char *second, int len)
{
	unsigned char	*f;
	unsigned char	*s;
	int			i;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	if (!len)
		return (0);
	while ((f[i] || s[i]) && i < len)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		i++;
	}
	return (0);
}
