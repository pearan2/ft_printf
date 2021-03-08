/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:44:20 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 23:16:47 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_c_p(t_info *info, size_t num_len)
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

void				ft_printf_c_w(t_info *info, long long remain)
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

long long			ft_get_rm_c(t_info *info, size_t num_len)
{
	long long		ret;

	if (info->width == -1)
		return (0);
	ret = (long long)info->width;
	ret -= num_len;
	if (ret >= 0)
		return (ret);
	return (0);
}

void				ft_printf_c_m(t_info *info, size_t num_len, char c)
{
	ft_putchar(c);
	ft_printf_c_w(info, ft_get_rm_c(info, num_len));
}

void				ft_printf_c(t_info *info, va_list *ap, int is_per)
{
	char		value;
	size_t		num_len;

	value = '%';
	if (is_per == 0)
		value = va_arg(*ap, int);
	if (info->prec != -1 && is_per == 0)
		info->flag_zero = 0;
	num_len = 1;
	if (info->flag_minus)
		ft_printf_c_m(info, num_len, value);
	else
	{
		ft_printf_c_w(info, ft_get_rm_c(info, num_len));
		ft_putchar(value);
	}
}
