/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-sal <mben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:45:46 by mben-sal          #+#    #+#             */
/*   Updated: 2023/03/04 12:19:41 by mben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*alloc_ptr(char const *s1, char const *s2, char const *s3)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	else
		return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!s3)
		s3 = ft_strdup("");
	ptr = alloc_ptr(s1, s2, s3);
	i = 0;
	j = 0;
	k = 0;
	while (s3[j])
		ptr[j++] = s3[k++];
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
