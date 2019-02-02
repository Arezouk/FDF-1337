# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hessabra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:14:45 by hessabra          #+#    #+#              #
#    Updated: 2019/01/11 22:52:24 by arezouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = Sources/*.c Functions/*.c
INC = Includes/
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit $(SRC) -I $(INC)

clean:
		    rm -f $(OBJ)

fclean: clean
		    rm -f $(NAME)

re: fclean all
