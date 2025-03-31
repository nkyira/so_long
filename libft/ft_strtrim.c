/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:50 by jodavis           #+#    #+#             */
/*   Updated: 2024/10/12 15:55:40 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	end = ft_strlen(s1);
	if (!ft_strlen(s1) || !ft_strlen(s1))
		return (ft_strdup(s1));
	if (end == 0)
		return (ft_strdup(NULL));
	while (charcheck(s1[start], set))
		start++;
	while (charcheck(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
