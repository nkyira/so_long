/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:40:42 by jodavis           #+#    #+#             */
/*   Updated: 2024/11/02 16:13:28 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(int n)
{
	int	count;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
		write(1, "-", 1);
	}
	conv_alg(n, 10, "0123456789", &count);
	return (count);
}

int	ft_putui(unsigned int n)
{
	int	count;

	count = 0;
	conv_alg(n, 10, "0123456789", &count);
	return (count);
}

int	ft_puthex(unsigned int n, char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		conv_alg(n, 16, "0123456789abcdef", &count);
	else if (c == 'X')
		conv_alg(n, 16, "0123456789ABCDEF", &count);
	return (count);
}
