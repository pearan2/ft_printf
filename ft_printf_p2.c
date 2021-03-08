/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:05:11 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 19:12:51 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printf_p_spe(t_info *info)
{
	long long		idx;
	char			c;

	c = ' ';
	idx = 0;
	if (info->flag_zero)
		c = '0';
	if (info->flag_minus)
	{
		ft_put_p_pre();
		while (idx < info->width - 2)
		{
			ft_putchar(c);
			idx++;
		}
	}
	else
	{
		while (idx < info->width - 2)
		{
			ft_putchar(c);
			idx++;
		}
		ft_put_p_pre();
	}
}
