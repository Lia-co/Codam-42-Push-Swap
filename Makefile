# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samudgal <samudgal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 12:36:48 by sliang            #+#    #+#              #
#    Updated: 2026/05/26 15:22:35 by samudgal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colours
GREEN = \033[1;92m
RED = \033[31m
WHITE = \033[1;60m
RESET = \033[0m

#files structure
NAME = 	push_swap
SRCS = 	make_list.c \
		check_flag.c \
		compute_disorder.c \
	   	main.c \
		handle_error.c \
		operations/op_push.c \
		operations/op_reverse_rotate.c \
		operations/op_rotate.c \
		operations/op_swap.c \
		chunk_sort.c \
		chunk_sort_utils.c \
		init_ops.c \
		select_algo.c \
		bench.c \
		utils_libft/ft_atoi.c \
		utils_libft/ft_isdigit.c \
		utils_libft/ft_lstadd_back.c \
		utils_libft/ft_lstclear.c \
		utils_libft/ft_lstlast.c \
		utils_libft/ft_lstnew.c \
		utils_libft/ft_lstsize.c \
		utils_libft/ft_strncmp.c \
		utils_libft/ft_putstr_fd.c \
		utils_libft/ft_putnbr_fd.c \
		utils_libft/ft_itoa.c \
		utils_libft/ft_calloc.c \
		utils_libft/ft_memset.c \
		utils_libft/ft_bzero.c \
		sort_three.c \
		radix_sort.c \
		parser_utils.c \
		selection_sort.c \
		adaptive_sort.c \

		
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME) # libft

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Object files is removed.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Program and objects files are removed.$(RESET)"

re: fclean all

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)push_swap program is compiled and ready to run.$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@echo "$(WHITE)compiling file $< ->$(RESET) $(GREEN)$@ $(RESET)"

.PHONY: all clean fclean re