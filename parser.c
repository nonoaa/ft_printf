/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:03:02 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:04:25 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_prec(const char *format, va_list ap, t_info *info)
{
	if (is_digit(*format))
	{
		if (info->status & DOT)
			info->prec = info->prec * 10 + *format - '0';
		else
			info->width = info->width * 10 + *format - '0';
	}
	else if (*format == '*')
	{
		if (info->status & DOT)
			info->prec = va_arg(ap, int);
		else
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->status |= MINUS;
				info->width *= -1;
			}
		}
	}
}

void	check_option(const char *format, va_list ap, t_info *info)
{
	if (*format == '0' && info->width <= 0 && info->prec <= 0)
		info->status |= ZERO;
	else if (*format == '-')
		info->status |= MINUS;
	else if (*format == '.')
		info->status |= DOT;
	else if (is_digit(*format) || *format == '*')
		check_width_prec(format, ap, info);
}

void	init_info(t_info *info)
{
	info->status = 0;
	info->width = 0;
	info->prec = 0;
	info->type = 0;
}
