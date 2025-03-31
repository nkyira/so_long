/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:01:25 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/11 16:00:19 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nl;

	i = 0;
	nl = ft_strlen(needle);
	if (!nl)
		return ((char *)haystack);
	if (!ft_strlen(haystack) || ft_strlen(haystack) < nl)
		return (NULL);
	while (haystack[i + nl - 1] && i + nl <= len)
	{
		if (!ft_strncmp(haystack + i, needle, nl))
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
