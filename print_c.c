/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:05:10 by bgales            #+#    #+#             */
/*   Updated: 2021/11/12 15:23:45 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./LIBFT/libft.h"
#include "libftprintf.h"

int	print_c(const char *str)
{
	unsigned int	i;
	va_list			ap;

	va_start(ap, str);
	va_arg(ap, int);
	write(1, i, 1);
	va_end(ap);
}
