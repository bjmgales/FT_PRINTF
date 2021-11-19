/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:06:32 by bgales            #+#    #+#             */
/*   Updated: 2021/11/14 00:10:37 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./LIBFT/libft.h"

int		ft_printf(const char *str, ...);
void	ft_printf_str(const char *str, unsigned int *counter);
void	ft_printf_int(int toconvert, unsigned int *counter);
void	ft_printf_void(const char *str, unsigned long \
toconvert, unsigned int *counter);
void	ft_putnbr_hex(unsigned long toconvert, unsigned int *counter, char maj);
void	ft_putnbr(unsigned int toconvert, unsigned int *counter);
char	*ft_itoa(int n);
#endif
