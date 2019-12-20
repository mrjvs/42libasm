# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-sni <jvan-sni@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 14:03:19 by jvan-sni       #+#    #+#                 #
#    Updated: 2019/12/17 17:39:26 by jvan-sni      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


############################### MAKEFILE  CONFIG ###############################

NAME = libasm.a
TNAME = testing
INCLUDES = include

FLAGS = -f macho64
TFLAGS = -Werror -Wextra -Wall

ASM = nasm
CC = gcc
AR = ar rcs

SRC_FOLDER = src/
SRC_FILES = test.s \
			ft_strlen.s \
			ft_write.s \
			ft_strcpy.s

TEST_FOLDER = test/
TEST_FILES = main.c


################################ MAKEFILE LOGIC ################################

FILES = $(addprefix $(SRC_FOLDER), $(SRC_FILES))
OBJ = $(FILES:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $^

src/%.o: src/%.s
	$(ASM) $(FLAGS) -o $@ $<


################################ TEST  MAKEFILE ################################

TFILES = $(addprefix $(TEST_FOLDER), $(TEST_FILES))
TOBJ = $(TFILES:.c=.o)

$(TNAME): $(NAME) $(TOBJ)
	$(CC) -I $(INCLUDES) $(TFLAGS) -lasm -o $@ $(TOBJ)

test/%.o: test/%.c
	$(CC) -I $(INCLUDES) $(TFLAGS) -c -o $@ $?


################################ MAKEFILE  CLEAN ################################

clean:
	rm -f $(OBJ) $(TOBJ)
	rm -f $(TOBJ)

fclean: clean
	rm -f $(NAME) $(TNAME)

re: fclean all
