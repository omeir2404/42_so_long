NAME	= so_long

CC		= cc -g

CFLAGS	= -Wall -Werror -Wextra 

SRC	= main.c srcs/utils.c GNL/get_next_line.c GNL/get_next_line_utils.c libft_functs/ft_strcmp.c libft_functs/ft_strrchr.c srcs/checks.c \
			srcs/map.c srcs/checks2.c libft_functs/ft_strlcpy.c srcs/path.c

OBJ	= main.o srcs/utils.o  GNL/get_next_line.o GNL/get_next_line_utils.o libft_functs/ft_strcmp.o libft_functs/ft_strrchr.o srcs/checks.o \
			srcs/map.o srcs/checks2.o libft_functs/ft_strlcpy.o srcs/path.o

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(SRC) -o $(NAME) -Iminilibx-linux -Lminilibx-linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm 

clean:		
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re