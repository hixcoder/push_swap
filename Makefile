# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 09:07:06 by hboumahd          #+#    #+#              #
#    Updated: 2022/05/13 15:39:48 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRCS_PUSH_SWAP =	stack_init.c push_swap_utils.c instructions_0.c instructions_1.c instructions_2.c instructions_3.c\
					sort_three.c sort_five.c sort_general.c sort_utils_0.c sort_utils_1.c sort_utils_2.c sort_utils_3.c		
					
OBJS_PUSH_SWAP = ${SRCS_PUSH_SWAP:.c=.o}


FT_PRINTF_FOLDER = ./ft_printf/
FT_PRINTF_FILES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr_base2.c ft_putnbr.c
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_FOLDER), $(FT_PRINTF_FILES))
OBJS_FT_PRINTF = ${SRCS_FT_PRINTF:.c=.o}

LIBS = ./ft_printf.a 

INCLUDES = push_swap.h ./ft_printf/ft_printf.h 

FLAGS = -Wall -Wextra -Werror
CC = cc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : $(OBJS_PUSH_SWAP) $(SRCS_FT_PRINTF) push_swap.o
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@echo "make the ft_printf.a"
	@echo "make the push_swap program"
	@$(CC) ${FLAGS} $(OBJS_PUSH_SWAP) $(LIBS) push_swap.c -o $(NAME)

all : $(NAME)

m: $(NAME)

b: $(OBJS_PUSH_SWAP) $(SRCS_FT_PRINTF) checker.o
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@echo "make the ft_printf.a"
	@echo "make the checker program"
	@$(CC) ${FLAGS} $(OBJS_PUSH_SWAP) $(LIBS) checker.c -o $(CHECKER)

clean :
	@rm -f $(LIBS) $(OBJS_FT_PRINTF) $(OBJS_PUSH_SWAP) checker.o push_swap.o

fclean : clean
	@rm -f $(NAME) $(CHECKER)

re : fclean all
