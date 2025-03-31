/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstprevious.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: jodavis <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/05 16:49:26 by jodavis        #+#    #+#                */
/*   Updated: 2025/02/05 17:02:21 by jodavis        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprevious(t_list *lst, t_list *node)
{
	if (!lst || !node || node == lst)
		return (NULL);
	while (lst->next)
	{
		if (lst->next == node)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
