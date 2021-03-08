# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:17:15 by honlee            #+#    #+#              #
#    Updated: 2020/12/28 23:32:31 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=\
		 ft_parse_util1.c\
		 ft_printf.c\
		 ft_printf_d1.c\
		 ft_put_util1.c\
		 ft_put_util2.c\
		 ft_parse_util2.c\
		 ft_gs_util1.c\
		 ft_gs_util2.c\
		 ft_gs_util3.c\
		 ft_printf_d2.c\
		 ft_printf_p1.c\
		 ft_printf_p2.c\
		 ft_printf_u1.c\
		 ft_printf_u2.c\
		 ft_printf_c1.c\
		 ft_printf_s1.c\
		 ft_printf_x1.c\
		 ft_printf_x2.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
CF		= -Wall -Wextra -Werror

.c.o	:
		${CC} ${CF} -c ${<} -o ${<:.c=.o}

$(NAME) : 	${OBJS}
		ar -rc $(NAME) ${OBJS}

all		:	$(NAME)

clean	:
		rm -f ${OBJS}

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
