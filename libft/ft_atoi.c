/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:49:07 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/08 17:52:10 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		sign = -(*str - 44);
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		n = *str - 48 + (10 * n);
		str++;
	}
	return (sign * n);
}
