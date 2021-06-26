/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:19:13 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:31:38 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_width(int width, int status, int length, int *count)
{
	while (length < width)
	{
		if (status & ZERO)
		{
			ft_putchar('0');
			(*count)++;
		}
		else
		{
			ft_putchar(' ');
			(*count)++;
		}
		length++;
	}
}

void	putchar_count(char c, t_info *info, int *count)
{
	if ((info->status & ZERO) && (info->status & MINUS))
		info->status &= ~ZERO;
	if (info->status & MINUS)
	{
		ft_putchar(c);
		(*count)++;
		put_width(info->width, info->status, 1, count);
	}
	else
	{
		put_width(info->width, info->status, 1, count);
		ft_putchar(c);
		(*count)++;
	}
}
