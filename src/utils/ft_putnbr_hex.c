/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:27:49 by bgales            #+#    #+#             */
/*   Updated: 2021/11/25 14:33:18 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long toconvert, unsigned int *counter, char maj)
{
	char	*set;

	if (maj == 'X')
	{
		set = "0123456789ABCDEF";
	}
	else
		set = "0123456789abcdef";
	if (toconvert >= 16)
	{
		ft_putnbr_hex((toconvert / 16), counter, maj);
		ft_putnbr_hex((toconvert % 16), counter, maj);
	}
	else
	{
		*counter += write(1, &set[toconvert], 1);
	}
	return ;
}
