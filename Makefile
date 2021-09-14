# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 16:22:01 by akotzky           #+#    #+#              #
#    Updated: 2021/09/14 18:43:57 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCS	=	$(shell echo srcs/*.c)
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft.a

INCLS	=	-Iincls

CFLAGS	=	-Wall -Werror -Wextra
CC		=	gcc -g

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(info - Linking Philosophers binary)
	@$(CC) $(CFLAGS) $(OBJS) -L . -lft -o $(NAME)

$(LIBFT) :
	@make -C ./libft all
	@cp ./libft/incls/libft.h ./incls
	@cp ./libft/libft.a .

%.o : %.c
	$(info - Assembling $< to $@ file...)
	@$(CC) -g $(INCLS) -c $< -o $@

clean :
	$(info - Cleaning Philosophers object files...)
	@rm -rf $(OBJS)

fclean : clean
	$(info - Cleaning Philosophers binary...)
	@rm -rf $(NAME)
	$(info - Removing libft.a and libft.h files...)
	@rm -rf $(LIBFT) ./incls/libft.h
	@make -C ./libft clean

re : fclean echore all
	@make -C ./libft fclean

echore :
	$(info - - - - - - - - - - - - - - - - - - -)
	$(info - Recompilong Philosophers project...)
