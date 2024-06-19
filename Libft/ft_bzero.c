/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:34:37 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:15:49 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)s;
	i = 0;
	while (i < len)
	{
		temp[i] = '\0';
		i++;
	}
}
