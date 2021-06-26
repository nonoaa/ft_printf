/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:44:03 by byahn             #+#    #+#             */
/*   Updated: 2021/06/25 18:11:50 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ZERO 1
# define MINUS 2
# define DOT 4
# define NEG 8
# define BASE16 16

typedef struct	s_info
{
	int			status;
	int			width;
	int			prec;
	char		type;
}				t_info;

int				is_flag(char c);
int				is_digit(char c);
int				is_type(char c);
int				is_option(char c);
void			ft_putchar(char c);
void			put_width(int width, int status, int length, int *count);
void			putchar_count(char c, t_info *info, int *count);
void			check_width_prec(const char *format, va_list ap, t_info *info);
void			check_option(const char *format, va_list ap, t_info *info);
void			init_info(t_info *info);
int				ft_strlen(char *str);
void			ft_putstr(char *str, int len, int *count);
void			putstr_count(char *str, t_info *info, int *count);
int				num_abs(long long n);
int				num_length(long long n, long long base);
char			*ft_itoa(long long n, long long base, t_info *info);
char			*check_num(long long n, long long base, t_info *info);
char			*putprec_nbr(char *str, t_info *info);
void			putstr_width_minus(char *str, int len,
		t_info *info, int *count);
void			putstr_width(char *str, int len, t_info *info, int *count);
void			putnbr_count_neg(char *str, t_info *info, int *count);
void			putnbr_count_pos(char *str, t_info *info, int *count);
void			putnbr_count(long long n, t_info *info, int *count);
void			print_type(va_list ap, t_info *info, int *count);
void			print_format(const char *format, va_list ap, int *count);
int				ft_printf(const char *format, ...);

#endif
