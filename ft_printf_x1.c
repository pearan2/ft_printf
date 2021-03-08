/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 22:08:11 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_x_p(t_info *info, size_t num_len)
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

void				ft_printf_x_w(t_info *info, long long remain)
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

long long			ft_get_rm_x(t_info *info, size_t num_len)
{
	long long		ret;
	long long		len;

	len = (long long)num_len;
	if (info->width == -1)
		return (0);
	ret = (long long)info->width;
	len = len > info->prec ? len : info->prec;
	ret -= len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_x_m(t_info *info, size_t num_len,
								unsigned int value, int is_big)
{
	ft_printf_x_p(info, num_len);
	ft_put_xuint(value, is_big);
	ft_printf_x_w(info, ft_get_rm_x(info, num_len));
}

void				ft_printf_x(t_info *info, va_list *ap, int is_big)
{
	unsigned int			value;
	size_t					num_len;

	value = va_arg(*ap, unsigned int);
	if (info->prec != -1)
		info->flag_zero = 0;
	if (value == 0 && info->prec == 0)
		return (ft_printf_x_spe(info));
	num_len = ft_gs_xuint(value);
	if (info->flag_minus)
		ft_printf_x_m(info, num_len, value, is_big);
	else
	{
		if (!info->flag_zero)
			ft_printf_x_w(info, ft_get_rm_x(info, num_len));
		if (info->flag_zero)
			ft_printf_x_w(info, ft_get_rm_x(info, num_len));
		ft_printf_x_p(info, num_len);
		ft_put_xuint(value, is_big);
	}
}
