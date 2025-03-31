/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:56 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/07 15:43:53 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t l)
{
	size_t	rtn;
	size_t	sl;
	size_t	size;

	size = l;
	sl = ft_strlen(src);
	rtn = ft_strlen(dst) + sl;
	while (*dst)
	{
		if (!l)
			return (sl + size);
		l--;
		dst++;
	}
	if (!l)
		return (sl + size);
	ft_strlcpy(dst, src, l);
	return (rtn);
}
