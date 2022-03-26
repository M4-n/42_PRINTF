/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:36:01 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:48:22 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main()
{
	char q;
	q = '8';
	printf("Number char\n");
	printf("My func : %d\n", ft_isdigit(q));
	printf("Header func : %d\n", isdigit(q));
	q = 'R';
	printf("Non Number char\n");
	printf("My func : %d\n", ft_isdigit(q));
	printf("Header func : %d\n", isdigit(q));
	int x=1;
	printf("Int data type\n");
	printf("My func : %d\n", ft_isdigit(x));
	printf("Header func : %d\n", isdigit(x));
	return 0;
}*/
