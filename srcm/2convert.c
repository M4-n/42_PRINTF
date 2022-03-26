/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2convert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:23 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/25 09:38:56 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*sharp(t_format f)
{
	if (f.spec == 'X')
		return ("0X");
	return ("0x");
}

int	get_hex(t_format f, size_t n, size_t i)
{
	char	c;
	int		p;

	p = 0;
	if (n > 0 || (!i && (f.spec != 'p' || !f.dot)))
	{
		if (f.spec == 'X')
			c = HEXUP[n % 16];
		else
			c = HEXLOW[n % 16];
		n /= 16;
		i = 1;
		p += get_hex(f, n, i);
		p += write(1, &c, 1);
	}
	return (p);
}

int	print_address(t_format f, va_list ap)
{
	size_t	arg;
	int		p;
	int		num_len;

	p = 0;
	arg = va_arg(ap, size_t);
	num_len = ft_numlen_base(arg, 16);
	if (f.precision < num_len)
		f.precision = num_len;
	p += write(1, "0x", 2 * f.zero);
	f.width -= 2;
	if (!f.minus && f.zero && !f.dot)
		p += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	p += write(1, "0x", 2 * !f.zero);
	p += ft_putnchar_fd('0', 1, (f.precision - num_len) * (arg != 0));
	p += ft_putnchar_fd('0', 1, f.precision * (f.dot && !arg));
	if (num_len)
	{
		f.precision = get_hex(f, arg, arg);
		p += f.precision;
	}
	p += ft_putnchar_fd(' ', 1, (f.width - f.precision) * f.minus);
	return (p);
}

int	print_hex(t_format f, va_list ap)
{
	unsigned int	arg;
	int				p;
	int				num_len;

	p = 0;
	arg = va_arg(ap, unsigned int);
	num_len = ft_numlen_base(arg, 16);
	num_len *= !(!arg && !f.precision && f.dot);
	if (!f.dot || f.precision < num_len)
		f.precision = num_len;
	if (f.sharp && arg)
		f.width -= 2;
	p += ft_putlstr_fd(sharp(f), 1, 2 * (f.sharp && f.zero && arg));
	if (!f.minus && f.zero && !f.dot)
		p += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	p += ft_putlstr_fd(sharp(f), 1, 2 * (f.sharp && !f.zero && arg));
	p += ft_putnchar_fd('0', 1, f.precision - num_len);
	if (num_len)
		p += get_hex(f, arg, arg);
	if (f.minus)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (p);
}
