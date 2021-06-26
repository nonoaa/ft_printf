/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:26:34 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:55:52 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_count_neg(char *str, t_info *info, int *count)
{
	(info->width)--;
	if (info->status & ZERO)
	{
		ft_putchar('-');
		(*count)++;
		info->status &= ~NEG;
	}
	if (info->status & DOT && info->prec > 0)
	{
		if (!(str = putprec_nbr(str, info)))
		{
			*count = -1;
			return ;
		}
	}
	putstr_width(str, ft_strlen(str), info, count);
	free(str);
}

void	putnbr_count_pos(char *str, t_info *info, int *count)
{
	if (info->status & DOT)
	{
		if (!(str = putprec_nbr(str, info)))
		{
			*count = -1;
			return ;
		}
	}
	putstr_width(str, ft_strlen(str), info, count);
	free(str);
}

void	putnbr_count(long long n, t_info *info, int *count)
{
	char		*str;
	long long	base;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->status |= BASE16;
	base = info->status & BASE16 ? 16 : 10;
	if (!(str = check_num(n, base, info)))
	{
		*count = -1;
		return ;
	}
	if (info->status & ZERO && ((info->status & DOT && info->prec >= 0)
			|| info->status & MINUS))
		info->status &= ~ZERO;
	if (info->status & NEG)
		putnbr_count_neg(str, info, count);
	else
		putnbr_count_pos(str, info, count);
}
