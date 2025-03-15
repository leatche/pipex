# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 18:47:23 by tcherepoff        #+#    #+#              #
#    Updated: 2025/03/15 05:11:13 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS	=	srcs/path.c				\
			srcs/pipex.c			\

OBJS = $(SRCS:%.c=%.o)

LD_FLAGS = -Llibft -lft -ltermcap

INCLUDES =	-I. -Ilibft/include
FLAG = -Wall -Werror -Wextra $(INCLUDES)# -fsanitize=address -g3
RM = @rm -f
AR = ar rcs
CC = cc

.c.o:
			@$(CC) $(FLAG) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJS)
			@echo Compiling Libft
			@$(MAKE) -s -C ./libft
			@echo Linking Objects
			@$(CC) $(FLAG) $(OBJS) $(LD_FLAGS) -o $(NAME)
			@echo Done!

all:		$(NAME)

clean:
			@echo Cleaning Libft
			@$(MAKE) clean -s -C ./libft
			@echo Cleaning Objects
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -s -C ./libft
			@echo Cleaning $(NAME)
			$(RM) $(NAME)


re:			fclean all

rebonus: fclean