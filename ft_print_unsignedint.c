/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignedint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:29:04 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 17:19:56 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(unsigned int number)
{
	int	len;

	len = 0;
	while (number >= 10)
	{
		number = number / 10;
		len++;
	}
	len++;
	return (len);
}

static int	ft_put_unsigned_int_recur(unsigned int number)
{
	if (number >= 10)
	{
		if (ft_put_unsigned_int_recur(number / 10) == -1)
			return (-1);
	}
	if (ft_put_char(number % 10 + '0') == -1)
		return (-1);
	return (ft_get_size(number));
}

int	ft_put_unsignedint(int number)
{
	unsigned int	unsigned_num;

	if (number < 0)
		unsigned_num = (unsigned int)number;
	else
		unsigned_num = (unsigned int)number;
	if (ft_put_unsigned_int_recur(unsigned_num) == -1)
		return (-1);
	return (ft_get_size(number));
}
