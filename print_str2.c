/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:24:44 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:25:55 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_width_minus(char *str, int len, t_info *info, int *count)
{
	if (info->status & NEG)
	{
		ft_putchar('-');
		(*count)++;
	}
	if (info->type == 'p')
	{
		ft_putstr("0x", 2, count);
		info->width -= 2;
	}
	ft_putstr(str, len, count);
	put_width(info->width, info->status, len, count);
}

void	putstr_width(char *str, int len, t_info *info, int *count)
{
	if (info->status & MINUS)
		putstr_width_minus(str, len, info, count);
	else
	{
		if (info->type == 'p')
			info->width -= 2;
		put_width(info->width, info->status, len, count);
		if (info->status & NEG)
		{
			ft_putchar('-');
			(*count)++;
		}
		if (info->type == 'p')
			ft_putstr("0x", 2, count);
		ft_putstr(str, len, count);
	}
}
