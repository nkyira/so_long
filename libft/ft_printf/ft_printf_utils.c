/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:48:39 by jodavis           #+#    #+#             */
/*   Updated: 2024/11/02 16:14:00 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		return (write(1, s, ft_strlen(s)));
}

void	conv_alg(size_t nbr, size_t base, char *sb, int *count)
{
	if (nbr >= base)
	{
		conv_alg(nbr / base, base, sb, count);
	}
	write(1, &sb[nbr % base], 1);
	(*count)++;
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	write(1, "0x", 2);
	conv_alg((size_t)ptr, 16, "0123456789abcdef", &count);
	return (count + 2);
}
