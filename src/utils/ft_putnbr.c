/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:08:15 by bgales            #+#    #+#             */
/*   Updated: 2021/11/14 00:53:53 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int toconvert, unsigned int *counter)
{
	char	*set;

	set = "0123456789";
	if (toconvert > 9)
	{
		ft_putnbr((toconvert / 10), counter);
		ft_putnbr((toconvert % 10), counter);
	}
	else
	{
		*counter += write(1, &set[toconvert], 1);
	}
	return ;
}
