/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:27:11 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:47:11 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*#include <stdio.h>
int	main()
{
	char	*arr;
	arr = ft_calloc(5, sizeof(int));
	int i = -1;
	printf("Start address: %p\n", arr);
	while (++i < (int)(5*sizeof(int)))
		printf("%p , 0x%02x\n", &arr[i], arr[i]);
}*/
