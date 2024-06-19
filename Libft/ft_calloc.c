/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:34:56 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:15:53 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count > 0 && size > 0 && count > UINT_MAX / size)
		return (0);
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ptr = ft_memset(ptr, 0, total_size);
	return (ptr);
}
