/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_util1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:41:34 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 19:12:16 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '#'
			|| c == ' ' || c == '+')
		return (1);
	return (0);
}

long long				ft_get_width(const char *format,
								size_t *idx, va_list *ap)
{
	long long			ret;
	int					temp;

	ret = 0;
	if (format[*idx] == '*')
	{
		temp = va_arg(*ap, int);
		*idx += 1;
		return (temp);
	}
	if (!(format[*idx] >= '1' && format[*idx] <= '9'))
		return (0);
	while (format[*idx] >= '0' && format[*idx] <= '9')
	{
		ret = (ret * 10) + (format[*idx] - '0');
		*idx += 1;
	}
	return (ret);
}

long long				ft_get_prec(const char *format,
									size_t *idx, va_list *ap)
{
	unsigned int		ret;
	int					temp;

	ret = 0;
	if (format[*idx] != '.')
		return (-1);
	else
		*idx += 1;
	if (format[*idx] == '*')
	{
		temp = va_arg(*ap, int);
		*idx += 1;
		return (temp);
	}
	while (format[*idx] >= '0' && format[*idx] <= '9')
	{
		ret = (ret * 10) + (format[*idx] - '0');
		*idx += 1;
	}
	return (ret);
}

int						ft_get_denator(const char *format, size_t *idx)
{
	if (format[*idx] == 'h')
	{
		*idx += 1;
		if (format[*idx] == 'h')
		{
			*idx += 1;
			return (2);
		}
		return (1);
	}
	else if (format[*idx] == 'l')
	{
		*idx += 1;
		if (format[*idx] == 'l')
		{
			*idx += 1;
			return (4);
		}
		return (3);
	}
	else
		return (-1);
}

int						ft_is_format(const char *format, size_t *idx)
{
	char c;

	c = format[*idx];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
			|| c == '%' || c == 'n' || c == 'f' || c == 'g'
			|| c == 'e' || c == 'o')
		return (1);
	return (0);
}
