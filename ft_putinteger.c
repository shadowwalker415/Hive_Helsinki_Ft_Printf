/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinteger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:09:46 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 17:57:58 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(int number)
{
	int	len;

	len = 0;
	if (number == -2147483648)
		return (11);
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	len++;
	return (len);
}

static int	ft_put_number_recursive(int number)
{
	if (number == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (number < 0)
	{
		if (ft_put_char('-') == -1)
			return (-1);
		number = -number;
	}
	if (number >= 10)
	{
		if (ft_put_number_recursive(number / 10) == -1)
			return (-1);
	}
	if (ft_put_char(number % 10 + '0') == -1)
		return (-1);
	return (ft_get_size(number));
}

int	ft_put_number(int number)
{
	if (ft_put_number_recursive(number) == -1)
		return (-1);
	return (ft_get_size(number));
}
