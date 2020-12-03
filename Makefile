# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/22 17:32:04 by lverdoes      #+#    #+#                  #
#    Updated: 2020/12/03 16:02:46 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MANDATORY_SRC	= $(addprefix /mandatory, $(MANDATORY))
LST_SRC 		= $(addprefix /lst, $(LST))
NODE_SRC 		= $(addprefix /node, $(NODE))
ADDED_SRC 		= $(addprefix /added, $(ADDED))

MANDATORY =	\
	/ft_memset.c \
	/ft_bzero.c \
	/ft_memcpy.c \
	/ft_memccpy.c \
	/ft_memmove.c \
	/ft_memchr.c \
	/ft_memcmp.c \
	/ft_strlen.c \
	/ft_strlcpy.c \
	/ft_strlcat.c \
	/ft_strchr.c \
	/ft_strrchr.c \
	/ft_strnstr.c \
	/ft_strncmp.c \
	/ft_atoi.c \
	/ft_isalpha.c \
	/ft_isdigit.c \
	/ft_isalnum.c \
	/ft_isascii.c \
	/ft_isprint.c \
	/ft_toupper.c \
	/ft_tolower.c \
	/ft_calloc.c \
	/ft_strdup.c \
	/ft_substr.c \
	/ft_strjoin.c \
	/ft_strtrim.c \
	/ft_split.c \
	/ft_itoa.c \
	/ft_strmapi.c \
	/ft_putchar_fd.c \
	/ft_putstr_fd.c \
	/ft_putendl_fd.c \
	/ft_putnbr_fd.c

LST = \
	/ft_lstadd_back_bonus.c \
	/ft_lstadd_front_bonus.c \
	/ft_lstclear_bonus.c \
	/ft_lstdelone_bonus.c \
	/ft_lstfind_bonus.c \
	/ft_lstiter_bonus.c \
	/ft_lstlast_bonus.c \
	/ft_lstmap_bonus.c \
	/ft_lstnew_bonus.c \
	/ft_lstsize_bonus.c \

ADDED =	\
	/ft_append_bonus.c \
	/ft_array_size_bonus.c \
	/ft_arraydup_bonus.c \
	/ft_atod_bonus.c \
	/ft_atoi_base_bonus.c \
	/ft_counter_bonus.c \
	/ft_file_to_str_bonus.c \
	/ft_free_array_bonus.c \
	/ft_getline_bonus.c \
	/ft_iswhitespace_bonus.c \
	/ft_print_array_bonus.c \
	/ft_realloc_bonus.c \
	/ft_replace_bonus.c \
	/ft_sort_ints_bonus.c \
	/ft_split_set_bonus.c \
	/ft_str_contains_bonus.c \
	/ft_str_contains_not_bonus.c \
	/ft_str_to_lower_bonus.c \
	/ft_str_to_upper_bonus.c \
	/ft_strcmp_bonus.c \
	/ft_strxjoin_bonus.c \
	/ft_substrlen_bonus.c \
	/ft_swap_bonus.c \
	/ft_unique_chars_bonus.c \
	/get_next_line_bonus.c

NODE = \
	/ft_node_add_back_bonus.c \
	/ft_node_add_front_bonus.c \
	/ft_node_del_all_bonus.c \
	/ft_node_del_one_bonus.c \
	/ft_node_find_bonus.c \
	/ft_node_insert_after_bonus.c \
	/ft_node_insert_before_bonus.c \
	/ft_node_insert_sort_bonus.c \
	/ft_node_is_sorted_bonus.c \
	/ft_node_iter_bonus.c \
	/ft_node_join_bonus.c \
	/ft_node_last_bonus.c \
	/ft_node_merge_bonus.c \
	/ft_node_new_bonus.c \
	/ft_node_number_bonus.c \
	/ft_node_remove_one_bonus.c \
	/ft_node_size_bonus.c \
	/ft_node_sort_bonus.c \
	/ft_node_unlink_bonus.c \
	/ft_print_node_list_bonus.c

NAME = libft.a
HEADERS = libft.h

SRC	= $(addprefix src, $(MANDATORY_SRC) $(LST_SRC) $(NODE_SRC) $(ADDED_SRC))
OBJ = $(SRC:src/%.c=obj/%.o)

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
UNUSED	= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $?

obj/%.o: src/%.c
	@mkdir -p obj obj/mandatory obj/lst obj/added obj/node
	$(CC) $(FLAGS) -c $< -o $@

norm:
	@norminette $(addprefix ., $(MANDATORY) $(LST) $(ADDED) $(NODE)) 
	@norminette $(HEADERS) Makefile

.PHONY:	clean fclean re

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f */*/*.o
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *.a

re: fclean all

main: all
	$(CC) $(UNUSED) $(NAME) main.c && ./a.out
