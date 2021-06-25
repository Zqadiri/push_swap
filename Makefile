# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 10:14:46 by zqadiri           #+#    #+#              #
#    Updated: 2021/06/24 12:33:35 by zqadiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	YELLOW       := $(shell tput -Txterm setaf 3)
	PURPLE       := $(shell tput -Txterm setaf 5)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

NAME_PS = 	push_swap

NAME_CK = 	checker

CMPL = 		-Wall -Werror -Wextra -fsanitize=address

HELP = 		./helpers/read_function.c\
			./helpers/libft_functions.c\
			./helpers/common_functions.c\
			./helpers/find.c\

SRCS_CK = 	./checker_f/checker.c\
			./checker_f/errors.c\
			./checker_f/instruction.c\
			./checker_f/get_instruction.c\
		
		
SRCS_PS =	./push_swap_f/push_swap.c\
			./push_swap_f/sort_100_500.c\
			./push_swap_f/utils.c\
			./push_swap_f/parsing.c\
			./push_swap_f/instructions.c\
			./push_swap_f/instructions_2.c\

all:   $(NAME_PS)

$(NAME_PS) : $(SRCS_PS)
			 @gcc $(CMPL) $(SRCS_PS) $(HELP) -o $(NAME_PS)
			 @echo "${YELLOW}Building push_swap ...${RESET}"

bonus:	$(NAME_CK)

$(NAME_CK) : $(SRCS_CK)
			 @gcc  $(CMPL) $(SRCS_CK) $(HELP) -o $(NAME_CK)
			 @echo "${YELLOW}Building checker ...${RESET}"
			
clean:		

fclean: 	clean
			@rm -rf $(NAME_CK) $(NAME_PS)
			@echo "${PURPLE}Clean executables ${RESET}"

re:			fclean all

.PHONY: 	all fclean
