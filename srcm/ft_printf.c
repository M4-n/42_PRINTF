/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:05:17 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/17 10:56:32 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	convertion(t_format f, va_list ap)
{
	int	printed_len;

	printed_len = 0;
	if (f.spec == 'c' || f.spec == '%')
		printed_len += print_char(f, ap);
	if (f.spec == 's')
		printed_len += print_string(f, ap);
	if (f.spec == 'd' || f.spec == 'i' || f.spec == 'u')
		printed_len += numtochar(f, ap);
	if (f.spec == 'x' || f.spec == 'X')
		printed_len += print_hex(f, ap);
	if (f.spec == 'p')
		printed_len += print_address(f, ap);
	return (printed_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*curr;
	int		total_len;

	total_len = 0;
	va_start(ap, str);
	curr = (char *)str;
	while (*curr)
	{
		if (*curr == '%')
		{
			if (*(++curr))
				total_len += check_format(curr, ap);
			while (*curr && !ft_strchr(SPECS, *curr))
				curr++;
			if (!(*curr))
				curr = (char *)str;
		}
		else
			total_len += write(1, curr, 1);
		curr++;
	}
	va_end(ap);
	return (total_len);
}
