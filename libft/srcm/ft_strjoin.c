/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:42:46 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:53:20 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		count;

	joined = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	count = 0;
	i = -1;
	while (s1[++i])
	{
		joined[i] = s1[i];
		count++;
	}
	i = 0;
	while (s2[i])
		joined[count++] = s2[i++];
	joined[count] = 0;
	return (joined);
}
