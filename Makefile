# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 16:22:01 by akotzky           #+#    #+#              #
#    Updated: 2021/08/15 17:04:12 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	$(shell echo srcs/*.c)
OBJS	=	$(SRCS:.c=.o)

INCLS	=	-Iincls

CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(info - Linking philo binary)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(info - Assembling $< to $@ file...)
	@$(CC) -g $(INCLS) -c $< -o $@

clean :
	$(info - Cleaning Philosophers object files...)
	@rm -rf $(OBJS)

fclean : clean
	$(info - Cleaning Philosophers executable binary...)
	@rm -rf $(NAME)

re : fclean
	$(info - Recompilong Philosophes project...)

