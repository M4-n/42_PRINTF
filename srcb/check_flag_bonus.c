/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:38:00 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/22 06:52:18 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

t_format	check_flags(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECS, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

t_format	get_precision(char *str, t_format f)
{
	while (!ft_strchr(SPECS, *str))
	{
		if (ft_isdigit(*str))
		{
			f.precision = ft_atoi(str);
			break ;
		}
		str++;
	}
	return (f);
}

t_format	get_width(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECS, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (*str > '0' && *str <= '9')
		{
			f.width = ft_atoi(str);
			break ;
		}
		str++;
	}
	return (f);
}

int	check_format(char *str, va_list ap)
{
	t_format	f;

	f = get_width(str, newformat());
	f = check_flags(str, f);
	while (*str != '.' && !ft_strchr(SPECS, *str))
		str++;
	if (*str == '.')
	{
		f.dot = 1;
		f = get_precision(str++, f);
		while (!ft_strchr(SPECS, *str))
			str++;
	}
	if (f.width < 0)
	{
		f.minus = 1;
		f.width *= -1;
	}
	f.spec = *str;
	return (convertion(f, ap));
}
