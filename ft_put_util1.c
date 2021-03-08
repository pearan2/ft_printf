/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuilt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:09:17 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 21:09:22 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_putchar(char c)
{
	g_ret++;
	write(1, &c, 1);
}

void			ft_put_uint(unsigned int n)
{
	if (n / 10 != 0)
		ft_put_uint(n / 10);
	ft_putchar((char)(n % 10 + '0'));
}

void			ft_put_int(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_put_uint(n * (-1));
	}
	else if (n > 0)
		ft_put_uint(n);
	else
		ft_putchar('0');
}

void			ft_put_pre(t_info *info, int value)
{
	if (value >= 0 && info->flag_plus)
		ft_putchar('+');
	if (value >= 0 && info->flag_blank)
		ft_putchar(' ');
	if (value < 0)
		ft_putchar('-');
}

void			ft_put_address(unsigned long long n)
{
	if (n / 16 != 0)
		ft_put_address(n / 16);
	ft_putchar((char)("0123456789abcdef"[n % 16]));
}
