/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:51:59 by bgales            #+#    #+#             */
/*   Updated: 2021/11/14 10:14:56 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	whatsinmypercent(const char *str, va_list ap, unsigned int *counter)
{
	int	char_c;

	if (*str == 'c')
	{
		str++;
		char_c = va_arg(ap, int);
		*counter += write(1, &char_c, 1);
	}
	if (*str == 's')
		ft_printf_str(va_arg(ap, const char *), counter);
	if (*str == 'd' || *str == 'i')
		ft_printf_int(va_arg(ap, int), counter);
	if (*str == 'p' || *str == 'x' || *str == 'X')
		ft_printf_void(str, va_arg(ap, unsigned long), counter);
	if (*str == 'u')
		ft_putnbr(va_arg(ap, unsigned int), counter);
	if (*str == '%')
		*counter += write(1, (const void *) '%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	counter;

	counter = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			whatsinmypercent(&*str, ap, &counter);
			str++;
		}
		counter += write(1, &*str, 1);
		str++;
	}
	va_end(ap);
return (counter);
}

int	main(void)
{
	void *str;
	void *test;
	unsigned int	i = 4094967296;

	str = &test;
	//printf("nombre faux printf : %d\n", ft_printf("%c\n", '0'));
	printf("nombre vrai printf :%d\n", ft_printf("%c %c %c", '0', 'a', '9'));

}
