# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 09:07:06 by hboumahd          #+#    #+#              #
#    Updated: 2022/03/02 09:29:35 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_FOLDER = ./push_swap/
PUSH_SWAP_FILES = push_swap.c
SRCS_PUSH_SWAP = $(addprefix $(PUSH_SWAP_FOLDER), $(SRC))

FT_PRINTF_FOLDER = ./push_swap/ft_printf/
FT_PRINTF_FILES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr_base2.c ft_putnbr.c
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_FOLDER), $(FT_PRINTF_FILES))

SRCS = $(SRCS_FT_PRINTF) $(SRCS_PUSH_SWAP)
OBJS = ${OTHER_SRCS:.c=.o}

LIBS = ./push_swap/ft_printf.a 

INCLUDES = ./push_swap/push_swap.h ./push_swap/ft_printf/ft_printf.h 

# -g for the debugger
FLAGS = -Wall -Wextra -Werror 
CC = cc 

%.o : %.c ${INCLUDES}
	$(CC) ${FLAGS} -c $< -o $@
	
$(NAME) : $(OBJS)
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@echo "make the ft_printf.a" 
	@echo "make the push_swap program"
	@$(CC) $(OBJS) -o $(NAME)

all : $(NAME)  

clean :
	@rm -f $(LIBS) $(OBJS)

fclean : clean
	@rm -f ./push_swap/push_swap

re : fclean all
