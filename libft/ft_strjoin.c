/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:17:11 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/08 17:42:18 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	size_t	tlen;

	tlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	dup = malloc(tlen);
	if (!dup)
		return (NULL);
	*dup = '\0';
	ft_strlcat(dup, s1, tlen);
	ft_strlcat(dup, s2, tlen);
	return (dup);
}
