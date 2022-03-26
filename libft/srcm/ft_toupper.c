/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:33:39 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:57:18 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>
int main()
{
	char c;
    c = 'm';
    printf("%c -> %c", c, toupper(c));
    c = 'D';
    printf("\n%c -> %c", c, toupper(c));
    c = '9';
    printf("\n%c -> %c", c, toupper(c));
    return 0;
}*/
