/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:34 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:19:38 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*destination;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = 0;
	destination = NULL;
	if (ft_strlen(s) >= start)
	{
		sub_len = ft_strlen(s + start);
		if (sub_len > len)
			sub_len = len;
	}
	destination = malloc(sub_len + 1);
	if (destination == NULL)
		return (NULL);
	if (sub_len > 0)
		ft_strlcpy(destination, s + start, sub_len + 1);
	else
		destination[sub_len] = 0;
	return (destination);
}
