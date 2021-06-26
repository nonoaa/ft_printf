/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:25:04 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 18:07:16 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(va_list ap, t_info *info, int *count)
{
	char		type;

	type = info->type;
	if (type == '%')
		putchar_count('%', info, count);
	else if (type == 'c')
		putchar_count(va_arg(ap, int), info, count);
	else if (type == 's')
		putstr_count(va_arg(ap, char *), info, count);
	else if (type == 'd' || type == 'i')
		putnbr_count(va_arg(ap, int), info, count);
	else if (type == 'x' || type == 'X' || type == 'u')
		putnbr_count(va_arg(ap, unsigned int), info, count);
	else if (type == 'p')
		putnbr_count(va_arg(ap, long long), info, count);
	else
		putchar_count(type, info, count);
}

void	print_format(const char *format, va_list ap, int *count)
{
	t_info	info;

	while (*format)
	{
		init_info(&info);
		if (*format == '%')
		{
			format++;
			while (*format && !is_type(*format) && is_option(*format))
			{
				check_option(format, ap, &info);
				format++;
			}
			if (!(*format))
				continue;
			info.type = *format++;
			print_type(ap, &info, count);
			if (*count == -1)
				return ;
		}
		else
			putchar_count(*format++, &info, count);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			out;

	out = 0;
	va_start(ap, format);
	print_format(format, ap, &out);
	va_end(ap);
	return (out);
}
