/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:47:16 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/03 15:56:12 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*srt_src;
	char		*srt_dst;
	const char	*end_src;

	if (dst == NULL && src == NULL)
		return (dst);
	srt_src = (char *)src;
	srt_dst = (char *)dst;
	end_src = (char *)src + len;
	if (srt_dst > srt_src && srt_dst <= end_src)
	{
		while (len--)
			srt_dst[len] = srt_src[len];
	}
	else
		ft_memcpy(srt_dst, srt_src, len);
	return (dst);
}
