/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:53:18 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:56:50 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main()
{
	char c;
    c = 'm';
    printf("%c -> %c", c, tolower(c));
    c = 'D';
    printf("\n%c -> %c", c, tolower(c));
    c = '9';
    printf("\n%c -> %c", c, tolower(c));
    return 0;
}*/
