# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 21:15:19 by tcherepoff        #+#    #+#              #
#    Updated: 2025/03/12 14:13:25 by tcherepoff       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_GEN = ft_atoi.c     ft_itoa.c        ft_putnbr_fd.c  ft_strlcpy.c  ft_tolower.c ft_bzero.c    ft_memchr.c      ft_putstr_fd.c\
	ft_strlen.c   ft_toupper.c  ft_calloc.c   ft_memcmp.c      ft_split.c      ft_strmapi.c ft_isalnum.c  ft_memcpy.c      ft_strchr.c     ft_strncmp.c\
	ft_isalpha.c  ft_memmove.c     ft_strdup.c     ft_strnstr.c ft_isascii.c  ft_memset.c      ft_striteri.c   ft_strrchr.c\
	ft_isdigit.c  ft_putchar_fd.c  ft_strjoin.c    ft_strtrim.c ft_isprint.c  ft_putendl_fd.c  ft_strlcat.c    ft_substr.c\
	ft_itoa_unsigned.c     ft_itoa_base.c    ft_free_tab.c
SRCSBONUS = ft_lstnew_bonus.c     ft_lstadd_front_bonus.c     ft_lstsize_bonus.c     ft_lstlast_bonus.c      ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c     ft_lstclear_bonus.c     ft_lstiter_bonus.c     ft_lstmap_bonus.c
SRCS_GNL =		get_next_line/get_next_line.c			\
				get_next_line/get_next_line_utils.c

SRCS = $(SRCS_GEN) $(SRCS_GNL)
OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
BONUS = $(OBJS) $(OBJSBONUS)
FLAG = -Wall -Werror -Wextra -Iinclude
RM = rm -f
AR = ar rcs

.c.o:
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(BONUS)
			$(AR) $(NAME) $(BONUS)

all:		$(NAME)

clean:
			$(RM) $(BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus: fclean bonus

.PHONY: bonus all clean fclean re rebonus
