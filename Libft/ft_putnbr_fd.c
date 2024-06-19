/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:27:27 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/13 17:17:58 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int number)
{
	int	size;
	int	temp;

	size = 0;
	temp = number;
	if (number <= 0)
		size++;
	while (temp != 0)
	{
		temp = temp / 10;
		size++;
	}
	return (size);
}

static void	fill(size_t size, size_t end_position, int n, char buffer[])
{
	while (size > end_position)
	{
		buffer[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[15];
	size_t	size;
	size_t	end_position;

	end_position = 0;
	size = get_size(n);
	if (n == -2147483648)
	{
		buffer[0] = '-';
		buffer[1] = '2';
		n = 147483648;
		end_position = 2;
	}
	if (n < 0)
	{
		buffer[0] = '-';
		end_position = 1;
		n = -n;
	}
	fill(size, end_position, n, buffer);
	buffer[size] = '\0';
	write(fd, buffer, size);
}
