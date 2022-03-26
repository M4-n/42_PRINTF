/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:46:34 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:49:28 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	getnum(int n, char *str, int len, int offset)
{
	while (len > offset)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		getnum(n, str, len, 2);
	}
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		getnum(n, str, len, 1);
	}
	else
		getnum(n, str, len, 0);
	str[len] = 0;
	return (str);
}
