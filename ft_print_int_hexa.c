/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:18:24 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 18:07:57 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(unsigned int number)
{
	int	len;

	len = 0;
	while (number >= 16)
	{
		number = number / 16;
		len++;
	}
	len++;
	return (len);
}

static int	ft_convert_int_hexa(unsigned int number)
{
	if (number >= 16)
	{
		if (ft_convert_int_hexa(number / 16) == -1)
			return (-1);
		if (write(1, &HEXA_BASE[number % 16], 1) == -1)
			return (-1);
	}
	else
	{
		if (write(1, &HEXA_BASE[number % 16], 1) == -1)
			return (-1);
	}
	return (ft_get_size(number));
}

int	ft_put_int_hexa(unsigned int number)
{
	if (number == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_convert_int_hexa(number) == -1)
		return (-1);
	return (ft_get_size(number));
}
