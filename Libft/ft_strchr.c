/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:36:29 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:18:10 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	character;
	char	*temp;

	temp = (char *)s;
	character = c;
	while (*temp)
	{
		if (*temp == character)
			return (temp);
		temp++;
	}
	if (character == *temp)
		return (temp);
	return (0);
}
