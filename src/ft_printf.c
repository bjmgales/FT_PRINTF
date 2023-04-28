/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:51:59 by bgales            #+#    #+#             */
/*   Updated: 2021/11/25 13:35:46 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	formatfinder(const char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (*str == c)
		return (1);
	return (0);
}

int	whatsinmypercent(const char *str, va_list ap, unsigned int *counter)
{
	int	char_c;

	str++;
	if (*str == 'c')
	{
		char_c = va_arg(ap, int);
		*counter += write(1, &char_c, 1);
	}
	if (*str == 's')
		ft_printf_str(va_arg(ap, const char *), counter);
	if (*str == 'd' || *str == 'i')
		ft_printf_int(va_arg(ap, int), counter);
	if (*str == 'p')
		ft_printf_void(str, va_arg(ap, unsigned long), counter);
	if (*str == 'x' || *str == 'X')
		ft_printf_void(str, va_arg(ap, unsigned long), counter);
	if (*str == 'u')
		ft_putnbr(va_arg(ap, unsigned int), counter);
	if (*str == '%')
			*counter += write(1, "%", 1);
	else
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	counter;
	unsigned int	i;

	counter = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			counter += write(1, &str[i], 1);
		if (str[i] == '%')
		{
			whatsinmypercent(&str[i], ap, &counter);
			i++;
		}
		i++;
	}
	va_end(ap);
	return ((unsigned int)(counter));
}
