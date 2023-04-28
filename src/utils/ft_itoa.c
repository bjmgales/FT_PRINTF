/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:56:21 by bgales            #+#    #+#             */
/*   Updated: 2021/11/25 14:56:43 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getmalloc(int n)
{
	int		i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	isneg(int n, int sign)
{
	if (n < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

char	*ft_itoa(int n)

{
	char	*converted_str;
	int		i;
	int		divider;
	int		sign;

	i = 0;
	divider = getmalloc(n);
	sign = 0;
	sign = isneg(n, sign);
	converted_str = malloc((divider + sign + 1) * sizeof(char));
	if (converted_str == NULL)
		return (NULL);
	while (i < divider)
	{
		if (!sign)
			converted_str[divider - i - 1] = (n % 10) + 48;
		if (sign)
			converted_str[divider - i] = (10 - (n % 10) + '0' - 10);
		n /= 10;
		i++;
	}
	if (sign)
		converted_str[0] = '-';
	converted_str[sign + divider] = '\0';
	return (converted_str);
}
