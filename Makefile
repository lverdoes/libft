# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/22 17:32:04 by lverdoes      #+#    #+#                  #
#    Updated: 2020/12/03 01:37:49 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

MANDATORY =	\
	/mandatory/ft_memset.c \
	/mandatory/ft_bzero.c \
	/mandatory/ft_memcpy.c \
	/mandatory/ft_memccpy.c \
	/mandatory/ft_memmove.c \
	/mandatory/ft_memchr.c \
	/mandatory/ft_memcmp.c \
	/mandatory/ft_strlen.c \
	/mandatory/ft_strlcpy.c \
	/mandatory/ft_strlcat.c \
	/mandatory/ft_strchr.c \
	/mandatory/ft_strrchr.c \
	/mandatory/ft_strnstr.c \
	/mandatory/ft_strncmp.c \
	/mandatory/ft_atoi.c \
	/mandatory/ft_isalpha.c \
	/mandatory/ft_isdigit.c \
	/mandatory/ft_isalnum.c \
	/mandatory/ft_isascii.c \
	/mandatory/ft_isprint.c \
	/mandatory/ft_toupper.c \
	/mandatory/ft_tolower.c \
	/mandatory/ft_calloc.c \
	/mandatory/ft_strdup.c \
	/mandatory/ft_substr.c \
	/mandatory/ft_strjoin.c \
	/mandatory/ft_strtrim.c \
	/mandatory/ft_split.c \
	/mandatory/ft_itoa.c \
	/mandatory/ft_strmapi.c \
	/mandatory/ft_putchar_fd.c \
	/mandatory/ft_putstr_fd.c \
	/mandatory/ft_putendl_fd.c \
	/mandatory/ft_putnbr_fd.c

LST = \
	/lst/ft_lstadd_back_bonus.c \
	/lst/ft_lstadd_front_bonus.c \
	/lst/ft_lstclear_bonus.c \
	/lst/ft_lstdelone_bonus.c \
	/lst/ft_lstfind_bonus.c \
	/lst/ft_lstiter_bonus.c \
	/lst/ft_lstlast_bonus.c \
	/lst/ft_lstmap_bonus.c \
	/lst/ft_lstnew_bonus.c \
	/lst/ft_lstsize_bonus.c \

ADDED =	\
	/added/ft_append_bonus.c \
	/added/ft_array_size_bonus.c \
	/added/ft_arraydup_bonus.c \
	/added/ft_atod_bonus.c \
	/added/ft_atoi_base_bonus.c \
	/added/ft_counter_bonus.c \
	/added/ft_free_array_bonus.c \
	/added/ft_getline_bonus.c \
	/added/ft_iswhitespace_bonus.c \
	/added/ft_print_array_bonus.c \
	/added/ft_realloc_bonus.c \
	/added/ft_replace_bonus.c \
	/added/ft_sort_ints_bonus.c \
	/added/ft_split_set_bonus.c \
	/added/ft_str_contains_bonus.c \
	/added/ft_str_contains_not_bonus.c \
	/added/ft_str_to_lower_bonus.c \
	/added/ft_str_to_upper_bonus.c \
	/added/ft_strcmp_bonus.c \
	/added/ft_strxjoin_bonus.c \
	/added/ft_substrlen_bonus.c \
	/added/ft_swap_bonus.c \
	/added/ft_unique_chars_bonus.c \
	/added/get_next_line_bonus.c

NODE = \
	/node/ft_node_add_back_bonus.c \
	/node/ft_node_add_front_bonus.c \
	/node/ft_node_del_all_bonus.c \
	/node/ft_node_del_one_bonus.c \
	/node/ft_node_find_bonus.c \
	/node/ft_node_insert_after_bonus.c \
	/node/ft_node_insert_before_bonus.c \
	/node/ft_node_insert_sort_bonus.c \
	/node/ft_node_is_sorted_bonus.c \
	/node/ft_node_iter_bonus.c \
	/node/ft_node_join_bonus.c \
	/node/ft_node_last_bonus.c \
	/node/ft_node_merge_bonus.c \
	/node/ft_node_new_bonus.c \
	/node/ft_node_number_bonus.c \
	/node/ft_node_remove_one_bonus.c \
	/node/ft_node_size_bonus.c \
	/node/ft_node_sort_bonus.c \
	/node/ft_node_unlink_bonus.c \
	/node/ft_print_node_list_bonus.c

OBJ = $(addprefix obj, $(MANDATORY:.c=.o) $(LST:.c=.o) $(ADDED:.c=.o) $(NODE:.c=.o))

CC = gcc -Wall -Wextra -Werror

UNUSED = -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

HEADERS = libft.h

IGNORE = .gitignore

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $?

obj/%.o: %.c
	@mkdir -p obj obj/mandatory obj/lst obj/added obj/node
	$(CC) -c $< -o $@

norm:
	@norminette $(addprefix ., $(MANDATORY) $(LST) $(ADDED) $(NODE)) 
	@norminette $(HEADERS) Makefile

ignore:
	@echo $(NAME) > $(IGNORE)
	@echo .DS_Store >> $(IGNORE)
	@echo input >> $(IGNORE)
	@echo *.o >> $(IGNORE)
	@echo **/obj >> $(IGNORE)
	@echo a.out  >> $(IGNORE)
	@echo main.c >> $(IGNORE)
	@echo *.txt >> $(IGNORE)

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f *~
	@/bin/rm -f *.o
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.a

re: fclean all

main: all
	$(CC) $(UNUSED) $(NAME) main.c && ./a.out input
