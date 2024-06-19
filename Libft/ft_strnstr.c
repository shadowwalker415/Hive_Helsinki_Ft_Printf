/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:14 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:19:20 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	temp = (char *)haystack;
	if (*temp == '\0' && *needle == '\0')
		return (temp);
	if (temp && *needle == '\0' && len <= 0)
		return (temp);
	i = 0;
	while (temp[i] && i < len)
	{
		j = 0;
		while (needle[j] && temp[i + j] == needle[j] && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (&temp[i]);
		i++;
	}
	return (0);
}
