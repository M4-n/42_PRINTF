/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:26:39 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:53:32 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (src[j] && size && (i + j < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j)
		dst[i + j] = 0;
	while (src[j])
		j++;
	return (i + j);
}
