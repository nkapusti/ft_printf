NAME	= libftprintf.a

SRCS	= 

OBJS	= $(SRCS:.c=.o)

%.o : %c
	gcc $(FLAGS) -c $< -I$(HEADER) -o $@

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
