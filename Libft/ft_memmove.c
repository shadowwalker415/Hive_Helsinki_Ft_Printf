/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:36:03 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:15:04 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	i;

	if (!src && !dst)
		return (NULL);
	temp_dest = (char *)dst;
	temp_src = (char *)src;
	i = 0;
	if (temp_dest > temp_src)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
		return (dst);
	}
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dst);
}
