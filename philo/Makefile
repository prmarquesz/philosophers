# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:38:54 by proberto          #+#    #+#              #
#    Updated: 2022/02/17 19:24:13 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_HEADER = includes
PATH_SRC = src/main
PATH_TESTER = src/test

NAME = philo
MAIN = $(PATH_SRC)/philosophers.c
SRC = $(addprefix $(PATH_SRC)/, input_validation.c)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	
	@$(CC) $(MAIN) $(SRC) -I$(PATH_HEADER) -o $(NAME)

test:	
	@$(MAKE) -C $(PATH_TESTER)

run: 
	@./$(NAME) $(ARGS)

clean:
	rm $(NAME)
	@$(MAKE) clean -C $(PATH_TESTER)

fclean:	clean
	@$(MAKE) fclean -C $(PATH_TESTER)

re:	fclean all

.PHONY: all clean fclean re
