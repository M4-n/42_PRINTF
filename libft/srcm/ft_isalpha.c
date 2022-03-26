/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:58:25 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:47:48 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main()
{
	char q;
	q = 'A';
	printf("Upper case\n");
	printf("My func : %d\n", ft_isalpha(q));
	printf("Header func : %d\n", isalpha(q));
	q='a';
	printf("Lower case\n");
	printf("My func : %d\n", ft_isalpha(q));
	printf("Header func : %d\n", isalpha(q));
	q='@';
	printf("Non alphabet\n");
	printf("My func : %d\n", ft_isalpha(q));
	printf("Header func : %d\n", isalpha(q));
	return (0);
}*/
