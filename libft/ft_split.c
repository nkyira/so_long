/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodavis <jodavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:18:17 by jodavis           #+#    #+#             */
/*   Updated: 2025/02/19 07:52:46 by jodavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	charcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

size_t	nextc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	skip(char **ptr, char c)
{
	while (**ptr == c && **ptr)
		(*ptr)++;
}

void	freesplit(char **strtab, size_t i)
{
	while (i--)
		free(strtab[i]);
	free(strtab);
}

char	**ft_split(char const *s, char c)
{
	char	**strtab;
	size_t	count;
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	skip(&ptr, c);
	count = charcount(s, c);
	i = count - 1;
	strtab = (char **)malloc((count + 1) * sizeof(char *));
	if (!strtab)
		return (strtab);
	while (count--)
	{
		strtab[i - count] = ft_substr(ptr, 0, nextc(ptr, c));
		if (!strtab[i - count])
		{
			freesplit(strtab, i - count);
			return (NULL);
		}
		ptr = ptr + nextc(ptr, c);
		skip(&ptr, c);
	}
	strtab[i - count] = NULL;
	return (strtab);
}
