##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile template
##

#####################################################
#
# 					PARAMETERS
#
#####################################################
SOURCE	=	./main.c \
			./src/my_rpg.c	\
			./src/load/load_all.c	\
			./src/load/load_quest.c	\
			./src/load/csfml_structs/load_csfml_structs.c\
			./src/load/map/load_map.c	\
			./src/load/map/vertex_map.c	\
			./src/load/ui/load_interface.c	\
			./src/load/ui/fight/load_fight_interface.c	\
			./src/load/ui/game/load_game_interface.c	\
			./src/load/ui/game/load_gameui_buttons.c	\
			./src/load/ui/game/load_sound_menu.c\
			./src/load/ui/game/load_sound_menu_buttons.c\
			./src/load/ui/menu/load_menu_interface.c	\
			./src/load/ui/menu/load_menu_button.c\
			./src/load/ui/menu/load_how_to_play_menu.c\
			./src/load/window/load_window.c	\
			./src/unload/unload_all.c	\
			./src/unload/map/unload_map.c	\
			./src/unload/window/unload_window.c	\
			./src/unload/ui/unload_ui.c\
			./src/file_av/my_fscanf.c	\
			./src/game/loop.c	\
			./src/game/particles_loop.c	\
			./src/game/player_loop.c	\
			./src/game/event/event.c\
			./src/game/event/ui/ui_event.c\
			./src/game/event/ui/menu_ui_event.c\
			./src/game/event/ui/game_ui_event.c\
			./src/game/event/ui/sound_menu_event.c\
			./src/game/event/button/check_state.c\
			./src/game/event/button/check_soundmenu_state.c\
			./src/draw/ui/draw_ui.c\
			./src/draw/window/draw_window.c
OBJS	=	$(SOURCE:.c=.o)
OUT		=	my_rpg
CC		=	gcc
CFLAGS	+=	-W -Wall -Iincludes/
LFLAGS	=	-lmy -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio
LDFLAGS	=	-Llib/my

#####################################################
#
# 					RULES
#
#####################################################
all: $(OUT)

$(OUT): $(OBJS)
	make -C lib/my/ all
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS) $(LDFLAGS) $(CSFML)

clean:
	make -C lib/my/ clean
	$(RM) $(OBJS) *~ *# *.o *.gc* src/*.gc* src/*.o

fclean: clean
	make -C lib/my/ fclean
	$(RM) $(OUT)

re: fclean all

debug: fclean $(OBJS)
	make -C lib/my/ all
	$(CC) $(OBJS) -ggdb3 -o $(OUT) $(LFLAGS) $(LDFLAGS)

.PHONY: all clean fclean re debug

#####################################################
#
# 					UNIT TEST RULES
#
#####################################################
unit_tests: all
	make -C tests/ all

unit_tests_page: all
	make -C tests/ html_page

unit_tests_fclean: fclean
	make -C tests/ fclean

.PHONY: unit_tests unit_tests_page unit_tests_fclean
