/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:57:21 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/22 06:51:10 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_format
{
	int		space;
	int		sharp;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		minus;
	int		plus;
	int		neg;
	char	spec;
}	t_format;

# define SPECS "cspdiuxX%"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

# define INT_MIN -2147483648
# define UINT_MAX 4294967295

t_format	newformat(void);
t_format	get_width(char *str, t_format f);
t_format	get_precision(char *str, t_format f);
t_format	check_flags(char *str, t_format f);

int			ft_printf(const char *str, ...);
int			convertion(t_format f, va_list ap);
int			numtochar(t_format f, va_list ap);
int			print_char(t_format f, va_list ap);
int			print_string(t_format f, va_list ap);
int			print_hex(t_format f, va_list ap);
int			print_address(t_format f, va_list ap);
int			check_format(char *str, va_list ap);

#endif
