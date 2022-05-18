# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:22:32 by plehtika          #+#    #+#              #
#    Updated: 2021/12/08 18:00:32 by plehtika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./

INCLUDES = ./includes/

SRCS = memset bzero memcpy memccpy memmove memchr memcmp strlen strdup strcpy \
strncpy strcat strncat strlcat strchr strrchr strstr strnstr strcmp strncmp \
atoi isalpha isdigit isalnum isascii isprint toupper tolower \
memalloc memdel strnew strdel strclr striter striteri strmap strmapi strequ \
strnequ strsub strjoin strtrim strsplit itoa putchar putstr putendl putnbr \
putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone lstdel lstadd \
lstiter lstmap lstappend strstretch delarray

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(patsubst %,$(SRC_PATH)ft_%.c,$(SRCS)) -I$(INCLUDES) $(CFLAG)
	ar -rcs $(NAME) $(patsubst %,$(SRC_PATH)ft_%.o,$(SRCS))

clean:
	rm -f $(patsubst %,./ft_%.o,$(SRCS))

fclean: clean
	rm -f $(NAME)

re: fclean all
