/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:33:42 by honlee            #+#    #+#             */
/*   Updated: 2020/12/29 01:50:32 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

typedef struct		s_info
{
	long long		width;
	int				flag_zero;
	int				flag_sharp;
	int				flag_minus;
	int				flag_plus;
	int				flag_blank;
	int				flag_star;
	long long		prec;
	char			format;
	int				denator;
}					t_info;

extern int			g_ret;

void				ft_print_info(t_info *info);
int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
int					ft_is_flag(char c);
long long			ft_get_width(const char *format, size_t *idx, va_list *ap);
long long			ft_get_prec(const char *format, size_t *idx, va_list *ap);
int					ft_get_denator(const char *format, size_t *idx);
int					ft_is_format(const char *format, size_t *idx);
void				ft_put_int(int n);
void				ft_put_uint(unsigned int n);
void				ft_printf_d(t_info *info, va_list *ap);
void				ft_printf_p(t_info *info, va_list *ap);
int					ft_check_info(t_info *info);
size_t				ft_gs_int(int value);
size_t				ft_gs_uint(unsigned int value);
size_t				ft_gs_lint(long int value);
size_t				ft_gs_ulint(unsigned long int value);
size_t				ft_gs_llint(long long int value);
size_t				ft_gs_ullint(unsigned long long int value);
size_t				ft_gs_sint(short int value);
size_t				ft_gs_usint(unsigned short int value);
size_t				ft_gs_uchar(unsigned char value);
size_t				ft_gs_schar(signed char value);
size_t				ft_gs_address(unsigned long long n);
void				ft_put_pre(t_info *info, int value);
void				ft_printf_d_spe(t_info *info);
void				ft_put_address(unsigned long long n);
void				ft_put_p_pre(void);
void				ft_printf_p_spe(t_info *info);
void				ft_printf_u_spe(t_info *info);
void				ft_printf_u(t_info *info, va_list *ap);
void				ft_put_u_pre(t_info *info);
void				ft_printf_c_spe(t_info *info);
void				ft_printf_c(t_info *info, va_list *ap, int is_per);
void				ft_putstr(const char *str, size_t len);
size_t				ft_gs_str(const char *str);
void				ft_printf_s(t_info *info, va_list *ap);
size_t				ft_gs_xuint(unsigned int value);
void				ft_printf_x(t_info *info, va_list *ap, int is_big);
void				ft_printf_x_spe(t_info *info);
void				ft_put_xuint(unsigned int value, int is_big);

#endif
