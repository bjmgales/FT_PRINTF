/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:50:04 by bgales            #+#    #+#             */
/*   Updated: 2023/04/28 17:26:59 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(const char *str, unsigned int *counter)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	while (*str != '\0')
	{
		*counter += write(1, &*str, 1);
		str++;
	}
}

void	ft_printf_int(int toconvert, unsigned int *counter)
{
	char	*converted;
	int		i;

	i = 0;
	converted = ft_itoa(toconvert);
	while (converted[i] != '\0')
	{
		*counter += write(1, &converted[i], 1);
		i++;
	}
	free (converted);
}

void	ft_printf_void(const char *str, unsigned long toconvert,
									unsigned int *counter)
{
	if (*str == 'p')
	{
		write(1, "0x", 2);
		*counter += 2;
		ft_putnbr_hex(toconvert, counter, *str);
	}
	if (*str == 'x' || *str == 'X')
		ft_putnbr_hex((unsigned int)toconvert, counter, *str);
}
