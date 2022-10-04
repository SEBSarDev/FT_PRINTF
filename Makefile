CC = clang
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
HEADER = ft_printf.h libft/libft.h
SRCS = ft_printf_utils2.c ft_printf.c ft_get_conv.c ft_init_flags.c ft_itoa_base.c ft_printf_utils.c ft_treat_flag.c ft_treat_flag_details.c
OBJS = ${SRCS:.c=.o}
DSRCS = ./libft/*.c
DOBJS = ${DSRCS:.c=.o}

all : ${NAME}
%.o : %.c ${HEADER}
	$(CC) -c $(CFLAGS) $< 
$(NAME) : $(OBJS)
	make -C libft
	ar -rc $@ $(OBJS) $(DOBJS)
clean :
	make clean -C libft 
	rm -f $(OBJS)
fclean : clean
	rm -f libft/libft.a
	rm -f $(NAME)
re : fclean all
