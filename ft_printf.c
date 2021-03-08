/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:33:22 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 23:29:06 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				g_ret = 0;

void			ft_mapper(t_info *info, va_list *ap)
{
	if (info->format == 'd')
		ft_printf_d(info, ap);
	else if (info->format == 'p')
		ft_printf_p(info, ap);
	else if (info->format == 'u')
		ft_printf_u(info, ap);
	else if (info->format == 'c')
		ft_printf_c(info, ap, 0);
	else if (info->format == 's')
		ft_printf_s(info, ap);
	else if (info->format == 'i')
		ft_printf_d(info, ap);
	else if (info->format == 'x')
		ft_printf_x(info, ap, 0);
	else if (info->format == 'X')
		ft_printf_x(info, ap, 1);
	else if (info->format == '%')
		ft_printf_c(info, ap, 1);
}

void			ft_parser(const char *format, size_t *idx,
								t_info *info, va_list *ap)
{
	*idx += 1;
	while (ft_is_flag(format[*idx]))
	{
		if (format[*idx] == ' ')
			info->flag_blank = 1;
		else if (format[*idx] == '#')
			info->flag_sharp = 1;
		else if (format[*idx] == '+')
			info->flag_plus = 1;
		else if (format[*idx] == '-')
			info->flag_minus = 1;
		else if (format[*idx] == '0')
			info->flag_zero = 1;
		else if (format[*idx] == '*')
			info->flag_star = 1;
		*idx += 1;
	}
	info->width = ft_get_width(format, idx, ap);
	info->prec = ft_get_prec(format, idx, ap);
	info->denator = ft_get_denator(format, idx);
	info->format = format[*idx];
	*idx += 1;
}

void			ft_init_info(t_info *info)
{
	info->flag_zero = 0;
	info->flag_sharp = 0;
	info->flag_minus = 0;
	info->flag_plus = 0;
	info->flag_blank = 0;
	info->flag_star = 0;
	info->width = 0;
	info->prec = -1;
	info->denator = 0;
	info->format = 0;
}

int				ft_printf(const char *format, ...)
{
	size_t	idx;
	t_info	*info;
	va_list	ap;

	g_ret = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	va_start(ap, format);
	idx = 0;
	while (format[idx] != 0)
	{
		if (format[idx] == '%')
		{
			ft_init_info(info);
			ft_parser(format, &idx, info, &ap);
			if (!ft_check_info(info))
				return (-1);
			ft_mapper(info, &ap);
		}
		else
			ft_putchar(format[idx++]);
	}
	va_end(ap);
	free(info);
	return (g_ret);
}
