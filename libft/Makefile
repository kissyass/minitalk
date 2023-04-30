# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:09:13 by ykissiko          #+#    #+#              #
#    Updated: 2022/10/07 14:20:25 by ykissiko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c
OBJS    = $(SRCS:.c=.o)
NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f
AR		= ar rc
RANL	= ranlib

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):    $(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANL) $(NAME)

all:    $(NAME)

clean:
		$(RM) $(OBJS)
		$(RM) $(BNSOBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

