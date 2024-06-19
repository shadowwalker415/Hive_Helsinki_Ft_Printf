/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:47:48 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/20 16:33:47 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill_array(int size, int end_position, int n, char *array)
{
	while (size > end_position)
	{
		array[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		end_position;
	int		size;
	char	*array;

	end_position = 0;
	size = get_size(n);
	array = malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		array[0] = '-';
		array[1] = '2';
		n = 147483648;
		end_position = 2;
	}
	if (n < 0)
	{
		array[0] = '-';
		end_position = 1;
		n = -n;
	}
	fill_array(size, end_position, n, array);
	array[size] = '\0';
	return (array);
}
