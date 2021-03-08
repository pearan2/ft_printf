/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 21:46:10 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_s_p(t_info *info, size_t num_len)
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

void				ft_printf_s_w(t_info *info, long long remain)
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

long long			ft_get_rm_s(t_info *info, size_t num_len)
{
	long long		ret;

	if (info->width == 0)
		return (0);
	ret = info->width;
	if (info->prec != -1 && (long long)num_len > info->prec)
		num_len = (size_t)info->prec;
	ret -= (long long)num_len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_s_m(t_info *info, size_t num_len,
								const char *value)
{
	ft_putstr(value, num_len);
	ft_printf_s_w(info, ft_get_rm_s(info, num_len));
}

void				ft_printf_s(t_info *info, va_list *ap)
{
	const char			*value;
	size_t				num_len;

	value = va_arg(*ap, char *);
	if (info->prec != -1)
		info->flag_zero = 0;
	if (value == 0)
		value = "(null)";
	num_len = ft_gs_str(value);
	if (info->prec != -1 && info->prec < (long long)num_len)
		num_len = (size_t)info->prec;
	if (info->flag_minus)
		ft_printf_s_m(info, num_len, value);
	else
	{
		ft_printf_s_w(info, ft_get_rm_s(info, num_len));
		ft_putstr(value, num_len);
	}
}
