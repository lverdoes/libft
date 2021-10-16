# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/04 13:12:33 by lverdoes      #+#    #+#                  #
#    Updated: 2021/10/15 23:10:23 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror -pedantic $(UNUSED)
UNUSED	= -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function

SDIR	= src
ODIR	= obj
INC		= inc

_OBJS	= \
	$(addprefix libft/, $(LIBFT)) \
	$(addprefix ext/, $(EXT)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix list/, $(LIST)) \
	$(addprefix deque/, $(DEQUE)) \
	$(addprefix queue/, $(QUEUE)) \
	$(addprefix stack/, $(STACK)) \
	$(addprefix trie/, $(TRIE))

OBJS	= $(addsuffix .o, $(addprefix $(ODIR)/, $(_OBJS)))

LIBFT =	\
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlen \
	ft_strlcpy \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_strncmp \
	ft_atoi \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd

EXT = \
	ft_append \
	ft_array_size \
	ft_arraydup \
	ft_atod \
	ft_concat_array \
	ft_counter \
	ft_free \
	ft_intdup \
	ft_iswhitespace \
	ft_print_array \
	ft_print_bits \
	ft_print_int_array \
	ft_realloc \
	ft_replace \
	ft_reverse_bits \
	ft_split_strchr \
	ft_split_strnstr \
	ft_str_contains_none \
	ft_str_contains_only \
	ft_str_to_lower \
	ft_str_to_upper \
	ft_strcmp \
	ft_strxjoin \
	ft_substrlen \
	ft_swap \
	ft_unique_chars

GNL = \
	ft_getfile \
	get_next_line

LIST = \
	ft_list_add_back \
	ft_list_add_front \
	ft_list_combine \
	ft_list_del_all \
	ft_list_del_one \
	ft_list_dup \
	ft_list_find \
	ft_list_insert_after \
	ft_list_insert_before \
	ft_list_insert_sort \
	ft_list_is_sorted \
	ft_list_iter \
	ft_list_index \
	ft_list_join \
	ft_list_last \
	ft_list_new \
	ft_list_number \
	ft_list_remove_if \
	ft_list_remove_one \
	ft_list_size \
	ft_list_sort \
	ft_list_unlink \
	ft_list_print

DEQUE = \
	ft_deque_add_front \
	ft_deque_clear \
	ft_deque_reserve \

QUEUE = \
	ft_dequeue \
	ft_enqueue \
	ft_queue_clear \
	ft_queue_get_element \
	ft_queue_init \
	ft_queue_resize

STACK = \
	ft_stack_clear \
	ft_stack_get_top \
	ft_stack_init \
	ft_stack_pop \
	ft_stack_push \
	ft_stack_resize

TRIE = \
	ft_trie_clear \
	ft_trie_find \
	ft_trie_alloc \
	ft_trie_new \
	ft_trie_remove \
	ft_trie_size_content \
	ft_trie_size_nodes

SUBDIRS = \
	libft \
	ext \
	gnl \
	list \
	deque \
	queue \
	stack \
	trie

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Created $@\x1b[1A\x1b[M"

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR) $(addprefix $(ODIR)/, $(SUBDIRS))
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ 
	@echo "Compiling libft/$<\x1b[1A\x1b[1M"

clean:
	@$(RM) $(OBJS)
	@echo "Deleted libft/obj"

fclean: clean
	@$(RM) $(NAME) a.out .DS_Store
	@echo "Deleted $(NAME)"
	@echo ""

re: fclean all

test: all
	$(CC) $(CFLAGS) -I$(INC) main.c $(NAME)
	@./a.out
