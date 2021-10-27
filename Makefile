# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 16:22:01 by akotzky           #+#    #+#              #
#    Updated: 2021/10/27 12:34:58 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	srcs/cycles.c \
			srcs/ft_tools.c \
			srcs/main.c \
			srcs/ph_init.c \
			srcs/time_conv.c
OBJS	=	$(SRCS:.c=.o)
INCLS	=	-Iincls
CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(info - Linking Philosophers binary)
	@$(CC) $(CFLAGS) $(INCLS) $(OBJS) -o $(NAME)

%.o : %.c
	$(info - Assembling $< to $@ file...)
	@$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	$(info - Cleaning Philosophers object files...)
	@rm -rf $(OBJS)

fclean : clean
	$(info - Cleaning Philosophers binary...)
	@rm -rf $(NAME)

re : fclean echore all

echore :
	@printf "\e[1;92m"
	@printf "\n - - - - - - - - - - - - - - - - - - -\n"
	@printf "  Recompiling Philosophers project... \n"
	@printf " - - - - - - - - - - - - - - - - - - -\n"
	@printf "\e[0m"
