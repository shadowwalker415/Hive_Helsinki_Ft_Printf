/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnkwelle <jnkwelle@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:42:49 by jnkwelle          #+#    #+#             */
/*   Updated: 2024/05/25 14:36:04 by jnkwelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA_BASE "0123456789abcdef"
# define HEXA_CAPS "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "Libft/libft.h"

int	ft_put_char(int c);
int	ft_put_number(int number);
int	ft_put_unsignedint(int number);
int	ft_put_ptr_hexa(void *prt);
int	ft_put_str(char *string);
int	ft_put_int_hexa(unsigned int number);
int	ft_put_hexa_caps(unsigned int number);
int	ft_printf(const char *format, ...);
#endif
