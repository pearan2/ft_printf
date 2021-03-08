/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gs_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:30:19 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 14:32:58 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_gs_llint(long long int value)
{
	size_t					ret;
	unsigned long long int	u_val;

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

size_t				ft_gs_ullint(unsigned long long int value)
{
	size_t					ret;

	ret = 0;
	while (value / 10 != 0)
	{
		value = value / 10;
		ret++;
	}
	ret++;
	return (ret);
}

size_t				ft_gs_sint(short int value)
{
	size_t					ret;
	unsigned short int		u_val;

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

size_t				ft_gs_usint(unsigned short int value)
{
	size_t					ret;

	ret = 0;
	while (value / 10 != 0)
	{
		value = value / 10;
		ret++;
	}
	ret++;
	return (ret);
}
