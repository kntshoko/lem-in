# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/05 16:35:17 by kntshoko          #+#    #+#              #
#    Updated: 2020/01/05 17:02:24 by kntshoko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in.a
EXE = lem-in
MAIN = lem-in.c
LIB = libft/libft.a 
CC = gcc
FLAG = -Wall -Werror -Wextra
ARC = ar rc
SRC =	lem-in.c\

OBJ =	lem-in.o\

# all: $(NAME) $(NAME2)

$(NAME):
		$(CC) $(FLAG) -c $(SRC)
		$(ARC) $(NAME) $(OBJ)
		ranlib $(NAME)
		$(CC) $(FLAG) -o $(EXE) $(MAIN) $(LIB) $(NAME)

all: $(NAME)
	
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(EXE)

re: fclean all
