/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:19:26 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:19:43 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int len, int *count)
{
	int		i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	*count += i;
}

void	putstr_count(char *str, t_info *info, int *count)
{
	int			i;
	int			len;
	char		*nullstr;

	i = 0;
	nullstr = "(null)";
	if (!str)
		str = nullstr;
	len = ft_strlen(str);
	if ((info->status & ZERO) && (info->status & MINUS))
		info->status &= ~ZERO;
	if ((info->status & DOT) && info->prec >= 0 && info->prec < len)
		len = info->prec;
	if (info->status & MINUS)
	{
		ft_putstr(str, len, count);
		put_width(info->width, info->status, len, count);
	}
	else
	{
		put_width(info->width, info->status, len, count);
		ft_putstr(str, len, count);
	}
}
