##
## EPITECH PROJECT, 2024
## MakeFile
## File description:
## MakeFile
##

SRC 	=	main.c \
			source/destroy.c \
			source/draw_utils.c \
			source/errors.c \
			source/game.c \
			source/init.c \
			source/parsing_word.c \
			source/algorithm/word_color.c \
			source/algorithm/letter_input.c \
			source/event/main_while.c \
			source/event/in_game_event.c \
			source/render/all.c \
			source/render/screen_end.c \
			source/render/screen_game.c \
			source/render/screen_menu.c \


SRC_LIB =	$(wildcard lib/my/*.c) \
			$(wildcard lib/myprintf/*.c) \
			$(wildcard lib/myutils/*.c) \
			$(wildcard lib/mymaths/*.c) \






OBJ	=	$(SRC:.c=.o)
OBJ_LIB = $(SRC_LIB:.c=.o)

GRAY = \033[38;5;245m
RST = \033[0m

NAME = tusmo

CFLAGS	=	-g \
			-Wall \
			-Wextra \

FLAGS	=	-lcsfml-graphics \
            -lcsfml-window \
            -lcsfml-system \
            -lm \

cpt = 0
%.o: %.c
	@echo "$(GRAY)| => gcc $(CFLAGS)$<$(RST)"
	@gcc $(CFLAGS) -c $< -o $@
	$(eval cpt=$(shell echo $$(($(cpt)+1))))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@echo "$(GRAY)|"
	@echo "| ==> ./$(RST)$(NAME)$(GRAY) on$(RST) $(cpt)$(GRAY).c files"

	@gcc -o $(NAME) $(OBJ) $(OBJ_LIB) $(FLAGS)

	@rm -f $(OBJ) $(OBJ_LIB)

	@echo "$(GRAY)|\n| ==> Removed $(RST)$(cpt)$(GRAY).o files$(RST)"
	@echo "$(GRAY)°$(RST)"


clean:
	find . -name "*.o" -delete
	rm -f $(NAME)
	clear


fclean:	clean

re:	fclean all
