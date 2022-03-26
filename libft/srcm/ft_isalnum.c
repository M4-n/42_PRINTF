/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:53:47 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:47:27 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*#include <stdio.h>
#include <ctype.h>
int	main()
{
	char q,b;
	int x;
	q='a';
	b='9';
	x=5;
	printf("alphabet\n");
	printf("My func : %d\n", ft_isalnum(q));
	printf("Header : %d\n", isalnum(q));
	printf("Num char\n");
	printf("My func : %d\n", ft_isalnum(b));
	printf("Header : %d\n", isalnum(b));
	printf("Int data\n");
	printf("my func : %d\n", ft_isalnum(x));
	printf("Header : %d\n", isalnum(x));
}*/
