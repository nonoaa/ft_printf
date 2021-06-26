/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:59:55 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:00:28 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return (c == '0' || c == '-' || c == '.' || c == '*');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		is_option(char c)
{
	return (is_flag(c) || is_digit(c));
}
