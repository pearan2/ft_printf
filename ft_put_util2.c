/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:36:33 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 23:21:03 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_put_p_pre(void)
{
	ft_putchar('0');
	ft_putchar('x');
	return ;
}

void				ft_put_u_pre(t_info *info)
{
	if (info->flag_plus)
		ft_putchar('+');
	if (info->flag_blank)
		ft_putchar(' ');
}

void				ft_putstr(const char *str, size_t num)
{
	size_t		idx;

	idx = 0;
	while (idx < num && str[idx] != 0)
	{
		ft_putchar(str[idx]);
		idx++;
	}
}

void				ft_put_xuint(unsigned int value,
							int is_big)
{
	if (value / 16 != 0)
		ft_put_xuint(value / 16, is_big);
	if (!is_big)
		ft_putchar((char)("0123456789abcdef"[value % 16]));
	else
		ft_putchar((char)("0123456789ABCDEF"[value % 16]));
}
