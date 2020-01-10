# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-sni <jvan-sni@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 14:03:19 by jvan-sni       #+#    #+#                 #
#    Updated: 2020/01/10 12:34:18 by jvan-sni      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


############################### MAKEFILE  CONFIG ###############################

NAME = libasm.a
TNAME = testing
INCLUDES = include

FLAGS = -g -f macho64
TFLAGS = -g -Werror -Wextra -Wall

ASM = nasm
CC = gcc
AR = ar rcs

SRC_FOLDER = src/
SRC_FILES = ft_strlen.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_list_size.s \
			ft_list_push_front.s \
			ft_list_remove_if.s \
			ft_list_sort.s \
			ft_atoi_base.s

TEST_FOLDER = test/
TEST_FILES = main.c \
			test_ft_read.c \
			test_ft_write.c \
			test_ft_strlen.c \
			test_ft_strcpy.c \
			test_ft_strdup.c \
			test_ft_strcmp.c \
			test_ft_list_size.c \
			test_ft_list_push_front.c \
			test_ft_list_remove_if.c \
			test_ft_list_sort.c \
			test_ft_atoi_base.c


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
