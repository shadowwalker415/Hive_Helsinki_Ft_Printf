/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:29 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:19:34 by jnkwelle         ###   ########.fr       */
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

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*allocate(size_t len)
{
	char	*memo;

	memo = (char *)malloc(sizeof(char) * len + 1);
	if (memo == NULL)
		return (NULL);
	return (memo);
}

static void	fill(char *trimmed, char const *start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		trimmed[i] = start[i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	const char	*start;
	const char	*end;
	char		*trimmed_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = (char *)s1;
	end = start + get_len(s1);
	while (*start && is_in_set(*(start), set))
		start++;
	while (end > start && is_in_set(*(end - 1), set))
		end--;
	len = 0;
	len = end - start;
	trimmed_str = allocate(len);
	if (trimmed_str == NULL)
		return (NULL);
	fill(trimmed_str, start, len);
	trimmed_str[len] = '\0';
	return (trimmed_str);
}
