/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:02:48 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/11 20:31:15 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_para(int n, int l, int neg)
{
	char	*s;

	s = malloc(l + neg + 1);
	if (!s)
		return (NULL);
	if (neg)
		s[0] = '-';
	s[l + neg] = '\0';
	while (l--)
	{
		s[l + neg] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		t;
	int		l;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = 1;
	neg = 0;
	if (n < 0)
	{
		neg++;
		n = -n;
	}
	t = n / 10;
	while (t)
	{
		t /= 10;
		l++;
	}
	return (itoa_para(n, l, neg));
}
