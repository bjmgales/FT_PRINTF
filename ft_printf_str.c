/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:50:04 by bgales            #+#    #+#             */
/*   Updated: 2021/11/14 00:50:46 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(const char *str, unsigned int *counter)
{
	while (*str != '\0')
	{
		*counter += write(1, &*str, 1);
		str++;
	}
}

void	ft_printf_int(int toconvert, unsigned int *counter)
{
	char	*converted;

	converted = ft_itoa(toconvert);
	while (*converted != '\0')
	{
		*counter += write(1, &*converted, 1);
		converted++;
	}
}

void	ft_printf_void(const char *str, unsigned long toconvert,
									unsigned int *counter)
{
	if (*str == 'p')
	{
		write(1, "0x", 2);
		*counter += 2;
	}
	ft_putnbr_hex(toconvert, counter, *str);
}
