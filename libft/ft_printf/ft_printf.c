/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:51:16 by jodavis           #+#    #+#             */
/*   Updated: 2024/11/02 16:13:41 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	write_conv(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == '%')
		return (write(1, "%", 1));
	else if (*format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putdec(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putui(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), *format));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = ft_strlen(format);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += write_conv(format, args) - 2;
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
