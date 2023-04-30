LIBFT_PATH = libft/
PRINTF_PATH = ft_printf/
NAME	=	libft/libft.a ft_printf/libftprintf.a
RM		= rm -f
FLAGS		= -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
		make -C libft/
		make -C ft_printf/
		gcc server.c $(NAME) $(FLAGS) -o server
		gcc client.c $(NAME) $(FLAGS) -o client

bonus:
		make -C libft/
		make -C ft_printf/
		gcc bonus_server.c $(NAME) $(FLAGS) -o bonus_server
		gcc bonus_client.c $(NAME) $(FLAGS) -o bonus_client
clean:
		make -C $(LIBFT_PATH) clean
		make -C $(PRINTF_PATH) clean
		$(RM) server client
		$(RM) bonus_server bonus_client 

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: re clean all fclean 