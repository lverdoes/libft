# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 09:38:30 by lverdoes      #+#    #+#                  #
#    Updated: 2021/07/15 10:12:20 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= hotrace
FLAGS	= -Wall -Wextra -Werror -O3
UNUSED	= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function
INCL	= ../includes
SRC 	= hotrace.c utils.c parse.c

all: $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all

$(NAME):
	gcc $(FLAGS) $(UNUSED) -o $(NAME) -I$(INCL) $(SRC) ../libft.a

test: re
	@./$(NAME)