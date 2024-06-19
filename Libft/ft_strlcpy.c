/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:01 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:18:57 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	remainder;
	size_t	src_len;

	temp_dest = (char *)dst;
	temp_src = (char *)src;
	remainder = dstsize;
	src_len = get_len(temp_src);
	while (*temp_src && remainder > 1)
	{
		*(temp_dest++) = *(temp_src++);
		remainder--;
	}
	if (remainder > 0)
		*temp_dest = '\0';
	return (src_len);
}
