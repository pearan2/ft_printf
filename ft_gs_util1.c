/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gs_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:18:08 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 18:34:05 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_gs_int(int value)
{
	size_t				ret;
	unsigned int		u_val;

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

size_t				ft_gs_uint(unsigned int value)
{
	size_t				ret;

	ret = 0;
	while (value / 10 != 0)
	{
		value = value / 10;
		ret++;
	}
	ret++;
	return (ret);
}

size_t				ft_gs_lint(long int value)
{
	size_t				ret;
	unsigned long int	u_val;

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

size_t				ft_gs_ulint(unsigned long int value)
{
	size_t				ret;

	ret = 0;
	while (value / 10 != 0)
	{
		value = value / 10;
		ret++;
	}
	ret++;
	return (ret);
}
