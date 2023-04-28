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

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/**
@brief Converts an integer to a string.
 *
@param n The integer to be converted.
 *
@return A string representing the integer `n`. If memory allocation fails, returns `NULL`.
 */
		char	*ft_itoa(int n);

/**
@brief Prints an unsigned integer to the standard output.
 *
@param toconvert The unsigned integer to be printed.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
 */
		void	ft_putnbr(unsigned int toconvert, unsigned int *counter);

/**
@brief Prints an unsigned long integer as a hexadecimal number to the standard output.
 *
@param toconvert The unsigned long integer to be printed.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
@param maj If 'X', prints the hexadecimal number in uppercase; otherwise, prints it in lowercase.
 */
		void	ft_putnbr_hex(unsigned long toconvert, unsigned int *counter, char maj);

/**
@brief Prints a string to the standard output. If the string is `NULL`, prints "(null)" instead.
 *
@param str The string to be printed.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
 */
		void	ft_printf_str(const char *str, unsigned int *counter);

/**
@brief Prints an integer to the standard output.
 *
@param toconvert The integer to be printed.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
 */
		void	ft_printf_int(int toconvert, unsigned int *counter);

/**
@brief Prints an unsigned long integer as a hexadecimal number to the standard output.
 *
@param str A string that specifies the format of the output. If 'p', prints the unsigned long integer as a hexadecimal number with a leading "0x". If 'x' or 'X', prints the unsigned long integer as a hexadecimal number without a leading "0x".
@param toconvert The unsigned long integer to be printed.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
 */
		void	ft_printf_void(const char *str, unsigned long toconvert, unsigned int *counter);

/**
@brief Finds the first occurrence of a character in a string.
 *
@param str The string to be searched.
@param c The character to be found.
 *
@return 1 if the character is found in the string; otherwise, returns 0.
 */
		int		formatfinder(const char *str, char c);

/**
@brief Processes the format string that follows a '%' character and prints the corresponding output to the standard output.
 *
@param str A string that specifies the format of the output. The '%' character is included in this string.
@param ap A `va_list` object that contains the arguments specified in the format string.
@param counter A pointer to an unsigned integer that stores the total number of characters printed so far.
 *
@return 0 if the format string is corresponding to %cspdiuxX flags.
**/
int	whatsinmypercent(const char *str, va_list ap, unsigned int *counter);

/**

@brief Prints a formatted string to stdout.

This function prints a formatted string to stdout. It accepts a variable number

of arguments, which are specified in the format string using '%' format specifiers.

@param str The format string to print.

@param ... The variable arguments to use in the format string.

@return The number of characters printed.
*/
int ft_printf(const char *str, ...);

#endif
