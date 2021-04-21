# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 10:14:46 by zqadiri           #+#    #+#              #
#    Updated: 2021/04/21 14:32:41 by zqadiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = 	push_swap

NAME_CK = 	checker

CMPL = 		-Wall -Werror -Wextra

SRCS_CK = 	./checker_f/checker.c\
			./checker_f/errors.c\
			./checker_f/get_instruction.c\
		
		
SRCS_PS =	./push_swap_f/push_swap.c\
			./push_swap_f/global_sort.c\
			./push_swap_f/utils.c\
			./push_swap_f/parsing.c\
			./push_swap_f/instructions.c\

all : 		$(NAME_CK)  $(NAME_PS)

$(NAME_PS) : $(SRCS_PS)
			 gcc $(CMPL) $(SRCS_PS) -o $(NAME_PS)

$(NAME_CK) : $(SRCS_CK)
			 gcc  $(CMPL) $(SRCS_CK) -o $(NAME_CK)

clean : 
			rm ./includes/checker.h.gch

fclean : 
			$(NAME_CK)  $(NAME_PS)
			rm ./includes/checker.h.gch

.PHONY: 	all clean fclean
		
		
		
