/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:56:37 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:50:29 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptrd;
	char	*ptrs;

	ptrd = (char *)dst;
	ptrs = (char *)src;
	i = 0;
	if (ptrd > ptrs)
	{
		ptrd += len - 1;
		ptrs += len - 1;
		while (i++ < len)
			*(ptrd--) = *(ptrs--);
	}
	else
	{
		while (i++ < len)
			*(ptrd++) = *(ptrs++);
	}
	return (dst);
}
