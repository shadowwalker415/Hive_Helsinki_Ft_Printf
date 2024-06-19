/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:35:58 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:15:00 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (!dst && !src)
		return (NULL);
	temp_dest = (char *)dst;
	temp_src = (char *)src;
	while (n--)
		*(temp_dest++) = *(temp_src++);
	return (dst);
}
