# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 09:07:06 by hboumahd          #+#    #+#              #
#    Updated: 2022/05/13 16:09:14 by hboumahd         ###   ########.fr        #
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

GET_NEXT_LINE_FOLDER = ./get_next_line/
GET_NEXT_LINE_FILES = get_next_line.c get_next_line_utils.c
SRCS_GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_FOLDER), $(GET_NEXT_LINE_FILES))

OTHER_SRCS = $(SRCS_FT_PRINTF) $(SRCS_GET_NEXT_LINE) 
OTHER_OBJ = ${OTHER_SRCS:.c=.o}

LIBS = ft_printf.a get_next_line.a
INCLUDES = push_swap.h ./ft_printf/ft_printf.h ./get_next_line/get_next_line.h

FLAGS = -Wall -Wextra -Werror
CC = cc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : $(OBJS_PUSH_SWAP) $(OTHER_OBJ) push_swap.o
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	@echo "make the ft_printf.a"
	@echo "make the get_next_line.a"
	@echo "make the push_swap program"
	@$(CC) ${FLAGS} $(OBJS_PUSH_SWAP) $(LIBS) push_swap.c -o $(NAME)

all : $(NAME)

m: $(NAME)

b: $(OBJS_PUSH_SWAP) $(OTHER_OBJ) checker.o
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	@echo "make the ft_printf.a"
	@echo "make the get_next_line.a"
	@echo "make the checker program"
	@$(CC) ${FLAGS} $(OBJS_PUSH_SWAP) $(LIBS) checker.c -o $(CHECKER)

clean :
	@rm -f $(LIBS) $(OTHER_OBJ) $(OBJS_PUSH_SWAP) checker.o push_swap.o

fclean : clean
	@rm -f $(NAME) $(CHECKER)

re : fclean all
