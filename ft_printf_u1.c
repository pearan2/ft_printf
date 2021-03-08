/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 21:55:41 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_u_p(t_info *info, size_t num_len)
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

void				ft_printf_u_w(t_info *info, long long remain)
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

long long			ft_get_rm_u(t_info *info, size_t num_len)
{
	long long		ret;
	long long		len;

	len = (long long)num_len;
	if (info->width == -1)
		return (0);
	ret = (long long)info->width;
	len = len > info->prec ? len : info->prec;
	if (info->flag_blank || info->flag_plus)
		len++;
	ret -= len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_u_m(t_info *info, size_t num_len,
								unsigned int value)
{
	ft_put_u_pre(info);
	ft_printf_u_p(info, num_len);
	ft_put_uint(value);
	ft_printf_u_w(info, ft_get_rm_u(info, num_len));
}

void				ft_printf_u(t_info *info, va_list *ap)
{
	unsigned int			value;
	size_t					num_len;

	value = va_arg(*ap, unsigned int);
	if (info->prec != -1)
		info->flag_zero = 0;
	if (value == 0 && info->prec == 0)
		return (ft_printf_u_spe(info));
	num_len = ft_gs_uint(value);
	if (info->flag_minus)
		ft_printf_u_m(info, num_len, value);
	else
	{
		if (!info->flag_zero)
			ft_printf_u_w(info, ft_get_rm_u(info, num_len));
		ft_put_u_pre(info);
		if (info->flag_zero)
			ft_printf_u_w(info, ft_get_rm_u(info, num_len));
		ft_printf_u_p(info, num_len);
		ft_put_uint(value);
	}
}
