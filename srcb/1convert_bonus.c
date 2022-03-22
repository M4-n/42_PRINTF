/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1convert_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:16:46 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/22 06:51:31 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

char	sign(t_format f)
{
	if (f.plus)
		return ('+');
	return ('-');
}

int	print_num_left(t_format f, char *num, int num_len, int is_minus)
{
	int	p;

	p = 0;
	f.width -= (f.space && !is_minus && !f.plus && f.width);
	if (is_minus || f.plus)
		p += ft_putnchar_fd(sign(f), 1, 1);
	else if (f.space)
		p += ft_putnchar_fd(' ', 1, 1);
	if (f.zero || f.precision > num_len)
		p += ft_putnchar_fd('0', 1, f.precision - num_len);
	p += write(1, num, num_len);
	p += ft_putnchar_fd(' ', 1, f.width - f.precision - is_minus - f.plus);
	return (p);
}

int	print_num_right(t_format f, char *num, int num_len, int is_minus)
{
	int	p;

	p = 0;
	f.width -= (f.space && !is_minus && !f.plus && f.width);
	if (!f.zero)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision - is_minus - f.plus);
	if (f.width && f.zero && f.dot)
		p += ft_putnchar_fd(' ', 1, f.width - f.precision - is_minus - f.plus);
	if (is_minus || f.plus)
		p += ft_putnchar_fd(sign(f), 1, 1);
	else if (f.space)
		p += ft_putnchar_fd(' ', 1, 1);
	if (f.width && f.zero && !f.dot)
		p += ft_putnchar_fd('0', 1, f.width - f.precision - is_minus - f.plus);
	p += ft_putnchar_fd('0', 1, f.precision - num_len);
	p += write(1, num, num_len);
	return (p);
}

char	*get_numtochar(int arg, t_format f)
{
	if (arg < 0 && f.spec == 'u')
		return (ft_uitoa((unsigned)arg));
	else if (arg == INT_MIN && f.spec != 'u')
		return (ft_uitoa((unsigned)arg));
	return (ft_itoa(arg));
}

int	numtochar(t_format f, va_list ap)
{
	char	*num;
	int		arg;
	int		is_minus;
	int		num_len;
	int		printed_len;

	printed_len = 0;
	arg = va_arg(ap, int);
	is_minus = (arg < 0 && f.spec != 'u');
	if (is_minus)
		f.plus = 0;
	if (arg < 0 && f.spec != 'u' && arg != INT_MIN)
		arg *= -1;
	num = get_numtochar(arg, f);
	num_len = ft_strlen(num);
	if (*num == '0' && !f.precision && f.dot)
		num_len = 0;
	if (f.precision < num_len || !f.dot)
		f.precision = num_len;
	if (f.minus)
		printed_len += print_num_left(f, num, num_len, is_minus);
	else
		printed_len += print_num_right(f, num, num_len, is_minus);
	free(num);
	return (printed_len);
}
