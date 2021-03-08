/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:27:12 by honlee            #+#    #+#             */
/*   Updated: 2020/12/28 23:09:58 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_is_fine(t_info *info)
{
	if (info->format == 'd' || info->format == 'p'
			|| info->format == 'u' || info->format == 'c'
			|| info->format == 's' || info->format == 'i'
			|| info->format == 'x' || info->format == 'X'
			|| info->format == '%')
		return (1);
	else
		return (0);
}

int				ft_check_info(t_info *info)
{
	if (!ft_is_fine(info))
		return (0);
	if (info->width < 0)
	{
		info->width = info->width * (-1);
		info->flag_minus = 1;
	}
	if (info->prec < 0)
		info->prec = -1;
	if (info->flag_zero && info->flag_minus)
		info->flag_zero = 0;
	if (info->flag_plus && info->flag_blank)
		info->flag_blank = 0;
	if (info->flag_sharp &&
			(info->format == 'd' || info->format == 'i'))
		return (0);
	if (info->format == 's' &&
			(info->flag_plus || info->flag_sharp || info->flag_blank))
		return (0);
	if ((info->denator == 1 || info->denator == 2) &&
			(info->format == 'f' || info->format == 'e' || info->format == 'g'))
		return (0);
	return (1);
}
