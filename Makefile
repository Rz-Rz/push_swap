# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 11:11:35 by kdhrif            #+#    #+#              #
#    Updated: 2022/07/30 14:10:08 by kdhrif           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = ps.a
HEADERS = ft_ps.h
CC = gcc -Wall -Wextra -Werror
SRCS =
OBJ = $(SRCS:%.c=%.o)

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

all: $(PS)

$(PS) : $(OBJ)
	ar rcs $(PS) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o : %.c $(HEADERS)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) -o $@ -c $<

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_pushswap!$(DEF_COLOR)"

clean:
	rm -f srcs/*.o
	@echo "$(BLUE)ft_pushswap object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -f $(PS)
	@echo "$(CYAN)ft_pushswap executable files cleaned!$(DEF_COLOR)"

.PHONY: re all clean fclean bonus
