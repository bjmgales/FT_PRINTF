/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:51:59 by bgales            #+#    #+#             */
/*   Updated: 2021/11/12 15:02:51 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
/*
void	whatsinmypercent(const char *str)
{
	if (c == 'c')
		print_c()
	if (c == 's')
		print_s
	if (c == 'p')
		print_p
	if (c == 'd')
		print_d
	if (c == 'i')
		print_i
	if (c == 'u')
		print_u
	if (c == 'x')
		print_x
	if (c == '%')
		write(1, '%', 1);
}
*/
int	ft_printf(const char *str, ...)
{
	while (*str != '%' && *str != '\0')
	{
		write(1, &*str, 1);
		str++;
		if (*str == '%')
		{
			str++;
			//whatsinmypercent(&*str);
		}
	}

}

int	main(void)
{
	ft_printf("jajajaja");
}
