/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:36:05 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:58:10 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (lst)
	{
		curr = *lst;
		while (curr)
		{
			next = curr->next;
			ft_lstdelone(curr, del);
			curr = next;
		}
		*lst = NULL;
	}
}
