/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gs_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:36:23 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 22:03:00 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_gs_uchar(unsigned char value)
{
	size_t			ret;

	ret = 0;
	while (value / 10 != 0)
	{
		value = value / 10;
		ret++;
	}
	ret++;
	return (ret);
}

size_t				ft_gs_schar(signed char value)
{
	size_t			ret;
	unsigned char	u_val;

	ret = 0;
	u_val = value < 0 ? value * (-1) : value;
	while (u_val / 10 != 0)
	{
		u_val = u_val / 10;
		ret++;
	}
	ret++;
	return (ret);
}

size_t				ft_gs_address(unsigned long long n)
{
	size_t			ret;

	ret = 0;
	while (n / 16 != 0)
	{
		n = n / 16;
		ret++;
	}
	ret++;
	return (ret);
}

size_t				ft_gs_str(const char *str)
{
	size_t			ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}

size_t				ft_gs_xuint(unsigned int value)
{
	size_t			ret;

	ret = 0;
	while (value / 16 != 0)
	{
		value = value / 16;
		ret++;
	}
	ret++;
	return (ret);
}
