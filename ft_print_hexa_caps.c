/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_caps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:23:58 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 18:07:01 by jnkwelle         ###   ########.fr       */
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

static int	ft_convert_hexa_caps(unsigned int number)
{
	if (number >= 16)
	{
		if (ft_convert_hexa_caps(number / 16) == -1)
			return (-1);
		if (ft_put_char(HEXA_CAPS[number % 16]) == -1)
			return (-1);
	}
	else
	{
		if (ft_put_char(HEXA_CAPS[number]) == -1)
			return (-1);
	}
	return (ft_get_size(number));
}

int	ft_put_hexa_caps(unsigned int number)
{
	if (number == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_convert_hexa_caps(number) == -1)
		return (-1);
	return (ft_get_size(number));
}
