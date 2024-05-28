/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:09:49 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/25 13:09:47 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *string)
{
	int	count;

	count = 0;
	if (string == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (count += 6);
	}
	while (*string != '\0')
	{
		if (ft_put_char(*string) == -1)
			return (-1);
		count++;
		string++;
	}
	return (count);
}
