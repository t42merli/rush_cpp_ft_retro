# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:38:31 by tmerli            #+#    #+#              #
#    Updated: 2019/09/26 14:11:44 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC = Enemy.class.cpp EnemyFleet.class.cpp Entity.class.cpp Game.class.cpp \
	Missile.class.cpp Player.class.cpp Star.class.cpp main.cpp

HEADER = incs/Define.hpp incs/Enemy.class.hpp incs/EnemyFleet.class.hpp incs/Entity.class.hpp \
	incs/Game.class.hpp incs/Missile.class.hpp incs/Player.class.hpp incs/Star.class.hpp

SRCDIR = srcs
SRC_E = $(addprefix $(SRCDIR)/, $(SRC))
FLAGS = -Wall -Wextra -Werror
CC = clang++
OBJ = $(SRC:.cpp=.o)
INCPATH = incs

LIB = -lncurses

all: $(NAME)

$(NAME): $(SRC_E) $(HEADER)
	$(CC) -I $(INCPATH) -c $(FLAGS) $(SRC_E)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
