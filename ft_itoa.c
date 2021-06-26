/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:20:22 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 17:42:09 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			num_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int			num_length(long long n, long long base)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa(long long n, long long base, t_info *info)
{
	char		*out;
	int			len;
	char		*numbers;

	len = num_length(n, base);
	numbers = info->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	out[len--] = '\0';
	if (n < 0)
	{
		out[0] = '-';
		n *= -1;
	}
	if (n == 0)
		out[len] = '0';
	while (n != 0)
	{
		out[len] = numbers[num_abs(n % base)];
		n /= base;
		len--;
	}
	return (out);
}

char		*check_num(long long n, long long base, t_info *info)
{
	char		*str;

	if (info->status & DOT && info->prec >= 0 && n == 0)
		return ("");
	if (info->status & ZERO || info->status & DOT)
	{
		if (n < 0)
		{
			info->status |= NEG;
			n *= -1;
			if (!(str = ft_itoa(n, base, info)))
				return (0);
		}
		else
		{
			if (!(str = ft_itoa(n, base, info)))
				return (0);
		}
	}
	else
	{
		if (!(str = ft_itoa(n, base, info)))
			return (0);
	}
	return (str);
}

char		*putprec_nbr(char *str, t_info *info)
{
	char		*out;
	int			i;
	int			j;
	int			size;

	i = 0;
	j = 0;
	size = (info->prec > ft_strlen(str)) ? info->prec : ft_strlen(str);
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < info->prec - ft_strlen(str))
		out[i++] = '0';
	while (str[j])
		out[i++] = str[j++];
	out[i] = '\0';
	info->status &= ~DOT;
	return (out);
}
