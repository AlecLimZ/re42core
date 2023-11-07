NAME		=	libft.a
SDIR		=	sources
SRC			=	$(wildcard $(SDIR)/*.c)
ODIR		=	object
OBJ			=	$(patsubst $(SDIR)/%.c,  $(ODIR)/%.o, $(SRC))
CFLAGS		+=	-Wall -Werror -Wextra -std=c99

all:			$(ODIR) $(NAME)

$(ODIR):
				mkdir $@

$(ODIR)/%.o:	$(SDIR)/%.c
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):		$(OBJ)
				ar -v -q $@ $^

main:
				cc $(CFLAGS) main.c -L. -lft -o main

clean:
				rm -rf $(NAME) main

fclean:			clean
				rm -rf $(ODIR)
				rm -rf $(OBJ)

re:				fclean all

.PHONY:			all clean fclean re main
