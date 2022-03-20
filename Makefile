# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 09:07:06 by hboumahd          #+#    #+#              #
#    Updated: 2022/03/20 09:00:15 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_PUSH_SWAP =	push_swap.c stack_init.c push_swap_utils_1.c instructions_1.c instructions_2.c instructions_3.c\
					sort_three.c sort_five.c sort_handred.c sort_general.c sort_general_utils_1.c 
					
OBJS_PUSH_SWAP = ${SRCS_PUSH_SWAP:.c=.o}


FT_PRINTF_FOLDER = ./ft_printf/
FT_PRINTF_FILES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr_base2.c ft_putnbr.c
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_FOLDER), $(FT_PRINTF_FILES))
OBJS_FT_PRINTF = ${SRCS_FT_PRINTF:.c=.o}

LIBS = ./ft_printf.a 

INCLUDES = push_swap.h ./ft_printf/ft_printf.h 

# -g for the debugger
FLAGS = -Wall -Wextra -Werror 
CC = cc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : $(OBJS_PUSH_SWAP) $(SRCS_FT_PRINTF)
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@echo "make the ft_printf.a" 
	@echo "make the push_swap program"
	@$(CC) $(OBJS_PUSH_SWAP) $(LIBS) -o $(NAME)

all : $(NAME)  

clean :
	@rm -f $(LIBS) $(OBJS_FT_PRINTF) $(OBJS_PUSH_SWAP)

fclean : clean
	@rm -f push_swap

re : fclean all
