# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 16:22:01 by akotzky           #+#    #+#              #
#    Updated: 2021/10/26 17:43:55 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	$(shell echo srcs/*.c)
OBJS	=	$(SRCS:.c=.o)
INCLS	=	-Iincls
CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc -g

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(info - Linking Philosophers binary)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(info - Assembling $< to $@ file...)
	@$(CC) -g $(INCLS) -c $< -o $@

clean :
	$(info - Cleaning Philosophers object files...)
	@rm -rf $(OBJS)

fclean : clean
	$(info - Cleaning Philosophers binary...)
	@rm -rf $(NAME)

re : fclean echore all

echore :
	$(info - - - - - - - - - - - - - - - - - - -)
	$(info - Recompilong Philosophers project...)
