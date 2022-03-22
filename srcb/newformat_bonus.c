/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newformat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:06:45 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/22 06:52:39 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

t_format	newformat(void)
{
	t_format	new;

	new.space = 0;
	new.sharp = 0;
	new.zero = 0;
	new.dot = 0;
	new.width = 0;
	new.precision = 0;
	new.plus = 0;
	new.minus = 0;
	new.spec = 0;
	return (new);
}
