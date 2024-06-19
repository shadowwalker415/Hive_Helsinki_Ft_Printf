/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:09:58 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:18:06 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	is_first_letter;

	i = 0;
	is_first_letter = 0;
	while (*str)
	{
		if (*str != c && is_first_letter == 0)
		{
			is_first_letter = 1;
			i++;
		}
		else if (*str == c)
			is_first_letter = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if (start > end)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**free_memory(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static void	ft_initialize(size_t *i, size_t *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**split;

	ft_initialize(&i, &j, &start);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j] = word_dup(s, start, i);
			if (!(split[j++]))
				return (free_memory(split, j));
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
