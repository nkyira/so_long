/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:55:30 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/07 15:43:59 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*c_src;
	char		*c_dst;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	c_src = (char *)src;
	c_dst = (char *)dst;
	while (++i <= n)
		c_dst[i - 1] = c_src[i - 1];
	return (dst);
}
