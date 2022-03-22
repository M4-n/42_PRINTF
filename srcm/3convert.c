/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3convert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:04:44 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/21 13:09:14 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(t_format f, va_list ap)
{
	char	c;
	int		p;

	p = 0;
	if (f.spec == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		p += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	p += write(1, &c, 1);
	if (f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (p);
}

int	print_string(t_format f, va_list ap)
{
	char	*str;
	int		p;

	p = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(str) || f.neg)
		f.precision = ft_strlen(str);
	if (!f.minus && f.zero && !f.dot)
		p += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	p += ft_putlstr_fd(str, 1, f.precision);
	if (f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (p);
}
