# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 11:11:35 by kdhrif            #+#    #+#              #
#    Updated: 2022/11/17 21:16:34 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
HEADERS = ft_ps.h
CC = gcc -Wall -Wextra -Werror -g 
SRCS = action_a.c action_b.c action_r.c ft_utils.c linked_list_0.c linked_list_1.c parsing_0.c parsing_1.c push_swap.c sorting_0.c sorting_1.c algo_0.c algo_1.c algo_2.c algo_3.c ft_split.c ft_strjoin.c ft_utils_2.c
CHECKER = action_a.c action_b.c action_r.c ft_utils.c linked_list_0.c linked_list_1.c parsing_0.c parsing_1.c checker.c  algo_0.c algo_1.c algo_2.c algo_3.c ft_split.c ft_strjoin.c get_next_line.c get_next_line_utils.c sorting_0.c sorting_1.c ft_utils_2.c
OBJ = $(SRCS:%.c=%.o)
PRINTF = ./ft_printf
INC = ./ft_printf/libftprintf.a
# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

$(PS) : $(INC) $(OBJ)
	$(CC) -g3 $(OBJ) $(INC) -o $(PS)
	@echo "$(GREEN)ps compiled!$(DEF_COLOR)"

all: $(PS)

bonus: $(INC) $(CHECKER)
	$(CC) $(CHECKER) $(INC) -o checker
	@echo "$(GREEN)checker compiled!$(DEF_COLOR)"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

$(INC) :
	make -C $(PRINTF)

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_pushswap!$(DEF_COLOR)"

clean:
	rm -f *.o
	make -sC $(PRINTF) clean
	@echo "$(BLUE)ft_pushswap object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -f $(PS)
	rm -f checker
	make -sC $(PRINTF) fclean
	@echo "$(CYAN)ft_pushswap executable files cleaned!$(DEF_COLOR)"

.PHONY: re all clean fclean bonus
