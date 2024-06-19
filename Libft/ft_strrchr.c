/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:25 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:46 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	character;
	char	*temp;
	size_t	src_len;

	character = c;
	temp = (char *)s;
	src_len = get_len(temp);
	temp += src_len;
	while (src_len && *temp != character)
	{
		temp--;
		src_len--;
	}
	if (*temp == character)
		return (temp);
	return (NULL);
}
