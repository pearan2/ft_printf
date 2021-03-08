/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 19:04:48 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_p_p(t_info *info, size_t num_len)
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

void				ft_printf_p_w(t_info *info, long long remain)
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

long long			ft_get_rm_p(t_info *info, size_t num_len)
{
	long long		ret;
	long long		len;

	len = (long long)num_len;
	if (info->width == -1)
		return (0);
	ret = (long long)info->width;
	len = len > info->prec ? len : info->prec;
	len += 2;
	ret -= len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_p_m(t_info *info, size_t num_len,
								unsigned long long value)
{
	ft_put_p_pre();
	ft_printf_p_p(info, num_len);
	ft_put_address(value);
	ft_printf_p_w(info, ft_get_rm_p(info, num_len));
}

void				ft_printf_p(t_info *info, va_list *ap)
{
	unsigned long long int			value;
	size_t							num_len;

	value = va_arg(*ap, long long int);
	if (info->prec != -1)
		info->flag_zero = 0;
	if (value == 0 && info->prec == 0)
		return (ft_printf_p_spe(info));
	num_len = ft_gs_address(value);
	if (info->flag_minus)
		ft_printf_p_m(info, num_len, value);
	else
	{
		if (!info->flag_zero)
			ft_printf_p_w(info, ft_get_rm_p(info, num_len));
		ft_put_p_pre();
		if (info->flag_zero)
			ft_printf_p_w(info, ft_get_rm_p(info, num_len));
		ft_printf_p_p(info, num_len);
		ft_put_address(value);
	}
}
