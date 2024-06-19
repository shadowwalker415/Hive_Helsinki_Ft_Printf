/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:35:46 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:14:55 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*temp;
	char	*temp2;
	int		diff;

	if (n == 0)
		return (0);
	temp = (char *)s1;
	temp2 = (char *)s2;
	while (n--)
	{
		diff = (unsigned char)*temp - (unsigned char)*temp2;
		if (diff != 0)
			return (diff);
		temp++;
		temp2++;
	}
	return (0);
}
