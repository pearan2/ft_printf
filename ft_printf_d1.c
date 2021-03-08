/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 19:16:18 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_d_p(t_info *info, size_t num_len)
{
	long long			idx;

	idx = 0;
	if (info->prec > (long long)num_len)
	{
		while (idx < (info->prec - (long long)num_len))
		{
			ft_putchar('0');
			idx++;
		}
	}
}

void				ft_printf_d_w(t_info *info, long long remain)
{
	long long		idx;
	char			c;

	idx = 0;
	c = ' ';
	if (info->flag_zero)
		c = '0';
	while (idx < remain)
	{
		ft_putchar(c);
		idx++;
	}
}

long long			ft_get_remain(t_info *info, size_t num_len, int value)
{
	long long		ret;
	long long		len;

	len = (long long)num_len;
	if (info->width == -1)
		return (0);
	ret = (long long)info->width;
	len = len > info->prec ? len : info->prec;
	if (info->flag_blank || info->flag_plus || value < 0)
		len++;
	ret -= len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_f_m(t_info *info, size_t num_len, int value)
{
	ft_put_pre(info, value);
	ft_printf_d_p(info, num_len);
	if (value < 0)
		ft_put_uint(value * (-1));
	else
		ft_put_uint(value);
	ft_printf_d_w(info, ft_get_remain(info, num_len, value));
}

void				ft_printf_d(t_info *info, va_list *ap)
{
	int			value;
	size_t		num_len;

	value = va_arg(*ap, int);
	if (info->prec != -1)
		info->flag_zero = 0;
	if (value == 0 && info->prec == 0)
		return (ft_printf_d_spe(info));
	num_len = ft_gs_int(value);
	if (info->flag_minus)
		ft_printf_f_m(info, num_len, value);
	else
	{
		if (!info->flag_zero)
			ft_printf_d_w(info, ft_get_remain(info, num_len, value));
		ft_put_pre(info, value);
		if (info->flag_zero)
			ft_printf_d_w(info, ft_get_remain(info, num_len, value));
		ft_printf_d_p(info, num_len);
		if (value < 0)
			ft_put_uint(value * (-1));
		else
			ft_put_uint(value);
	}
}
