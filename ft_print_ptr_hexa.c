/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:43:11 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 17:23:34 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_ptr_hexa(unsigned long long address, int count)
{
	if (address >= 16)
	{
		count += ft_convert_ptr_hexa(address / 16, count);
		if (write(1, &HEXA_BASE[address % 16], 1) == -1)
			return (-1);
	}
	else
	{
		if (write(1, &HEXA_BASE[address], 1) == -1)
			return (-1);
	}
	count++;
	return (count);
}

int	ft_put_ptr_hexa(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	if (address == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 0;
	count = ft_convert_ptr_hexa(address, count);
	return (count + 2);
}
