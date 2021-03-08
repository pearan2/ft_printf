/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:13:45 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 20:15:51 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_printf_u_spe(t_info *info)
{
	long long			idx;
	char				c;

	idx = 0;
	c = ' ';
	if (info->flag_zero)
		c = '0';
	while (idx < info->width)
	{
		ft_putchar(c);
		idx++;
	}
	return ;
}
