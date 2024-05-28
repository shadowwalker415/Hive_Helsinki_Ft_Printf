/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:28:28 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/27 18:27:31 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_put_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_put_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_put_number(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_put_unsignedint(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += ft_put_ptr_hexa(va_arg(args, void *));
	else if (specifier == 'x')
		count += ft_put_int_hexa(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_put_hexa_caps(va_arg(args, unsigned int));
	else if (specifier == '%')
	{
		if (ft_put_char(specifier) == -1)
			return (-1);
		count++;
	}
	return (count);
}

static int	handle_format(const char **string, va_list args)
{
	int	check;

	++(*string);
	check = 0;
	if (**string != '\0')
	{
		check = ft_print_format(args, **string);
		if (check == -1)
			return (-1);
		++(*string);
		return (check);
	}
	return (0);
}

static int	handle_char(const char **string)
{
	int	check;

	check = 0;
	check = ft_put_char(**string);
	if (check == -1)
		return (-1);
	++(*string);
	return (check);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		check;

	if (!string)
		return (0);
	count = 0;
	check = 0;
	va_start(args, string);
	while (*string != '\0')
	{
		if (*string == '%')
			check = handle_format(&string, args);
		else
			check = handle_char(&string);
		if (check == -1)
			return (-1);
		count += check;
	}
	va_end(args);
	return (count);
}
