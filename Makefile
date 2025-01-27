##
## EPITECH PROJECT, 2024
## MakeFile
## File description:
## MakeFile
##

SRC 	=	main.c \
			\
			source/destroy.c \
			source/help_file.c \
			source/errors.c \
			source/game.c \
			source/init.c \
			source/parsing_word.c \
			\
			source/algorithm/word_color.c \
			source/algorithm/letter_input.c \
			\
			source/event/main_while.c \
			source/event/in_game_event.c \
			\
			source/utilitaries/corner_rectangle.c \
			source/utilitaries/debug_sf_shape.c \
			source/utilitaries/normal_rectangle.c \
			source/utilitaries/pictures.c \
			source/utilitaries/texts.c \
			source/utilitaries/csfml_shortcuts.c \
			\
			source/render/all.c \
			source/render/screen_end.c \
			source/render/screen_game.c \
			source/render/screen_menu.c \
			source/render/debug_file.c \


SRC_LIB =	lib/my/my_compute_power_rec.c \
			lib/my/my_compute_square_root.c \
			lib/my/my_getnbr.c \
			lib/my/my_is_prime.c \
			lib/my/my_isneg.c \
			lib/my/my_put_nbr.c \
			lib/my/my_putchar.c \
			lib/my/my_putstr.c \
			lib/my/my_revstr.c \
			lib/my/my_str_islower.c \
			lib/my/my_str_isupper.c \
			lib/my/my_strcapitalize.c \
			lib/my/my_strcat.c \
			lib/my/my_strcpy.c \
			lib/my/my_strdup.c \
			lib/my/my_strlen.c \
			lib/my/my_strlowcase.c \
			lib/my/my_strncat.c \
			lib/my/my_strncmp.c \
			lib/my/my_strcmp.c \
			lib/my/my_strncpy.c \
			lib/my/my_strstr.c \
			lib/my/my_strupcase.c \
			lib/my/my_swap.c \
			lib/mymaths/absolute.c \
			lib/mymaths/maximum.c \
			lib/mymaths/minimum.c \
			lib/mymaths/power_functions.c \
			lib/mymaths/rounding.c \
			lib/mymaths/square_root.c \
			lib/myprintf/flag_0.c \
			lib/myprintf/flag_diese.c \
			lib/myprintf/flag_len.c \
			lib/myprintf/my_get.c \
			lib/myprintf/my_numbers.c \
			lib/myprintf/my_printf.c \
			lib/myprintf/my_putexpo.c \
			lib/myprintf/my_putfloat.c \
			lib/myprintf/my_putpoint.c \
			lib/myprintf/specifiers.c \
			lib/myprintf/specifiers2.c \
			lib/myutils/convert_float_into_str.c \
			lib/myutils/convert_int_into_str.c \
			lib/myutils/convert_str_into_int.c \
			lib/myutils/get_len_of_int.c \
			lib/myutils/one_string.c \






OBJ	=	$(SRC:.c=.o)
OBJ_LIB = $(SRC_LIB:.c=.o)

GRAY = \033[38;5;245m
RST = \033[0m

NAME = tusmo

CFLAGS	=	-g \
			-Wall \
			-Wextra \
			-iquote./include \

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
