# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 10:14:46 by zqadiri           #+#    #+#              #
#    Updated: 2021/04/21 11:55:29 by zqadiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = 	push_swap

NAME_CK = 	checker

CMPL = 		-Wall -Werror -Wextra

SRCS_CK = 	./checker/checker.c\
			./checker/errors.c\
			./checker/get_instruction.c\
		
		
SRCS_PS =	./push_swap/push_swap.c\
			./push_swap/global_sort.c\
			./push_swap/utils.c\
			./push_swap/get_instruction.c\

all : 		$(NAME_CK) 

$(NAME_PS) : $(SRCS_PS)
			 gcc -o $(NAME_PS) $(CMPL) $(SRCS_PS)

$(NAME_CK) : $(SRCS_CK)
			 gcc -o $(NAME_CK) $(CMPL) $(SRCS_CK)


.PHONY: 	all clean
		
		
		
