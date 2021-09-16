# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 21:01:08 by akotzky           #+#    #+#              #
#    Updated: 2021/09/16 14:23:53 by akotzky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a
INCLS		=	-Iincls
SRCS		=	$(shell echo srcs/*.c)
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror 
CC			=	gcc

.PHONY : all clean fclean re pull echobjs echore

all : pull $(NAME)

pull :
	@git pull

$(NAME) : echobjs $(OBJS)
	@$(info - Archiving Libft object files...)
	@ar rcs $(NAME) $(OBJS)

%.o : %.c
	@$(CC) -g $(CFLAGS) $(INCLS) -c $< -o $@

clean :
	@$(info - Cleaning Libft object files...)
	@rm -rf $(OBJS)

fclean : clean 
	@$(info - Cleaning Libft library file...)
	@rm -rf $(NAME)

re : fclean echore all

echobjs :
	@$(info - Assembling Libft object files...)

echore :
	@$(info - Rebuilding Libft library project...)

