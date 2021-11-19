NAME= ft_printf.hf.a

SOURCES=ft_printf.c \
ft_printf_str.c \
ft_itoa.c \
ft_putnbr_hex.c \
ft_putnbr.c \


OBJS=	$(SOURCES:.c=.o)

BONUS=ft_lstnew.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

BONUS_OBJ= $(BONUS:.c=.o)

FLAGS=	-Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJS)
	ar crs $(NAME) $(OBJS)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)
clean :
	rm -rf $(OBJS) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME)
re : fclean all

bonus:$(BONUS_OBJ)
	ar crs $(NAME) $(BONUS_OBJ)

.PHONY : all clean fclean re

