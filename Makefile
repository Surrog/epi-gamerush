##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 francois1 ancel
## Last update Sun Mar 28 20:42:18 2010 francois1 ancel
##

NAME	= epikong_etape_4
OSNAME	= $(shell uname -s)
OSNAME	!= uname -s
CC	= gcc
RM	= rm -rf
SRCS	= err.c			\
	menu/menu_exec.c	\
	menu/menu_fct.c		\
	game_text.c		\
	next_level.c		\
	boss.c			\
	display.c		\
	exec_fct.c		\
	image_fct.c		\
	key_func.c		\
	special_action.c	\
	act.c			\
	ia.c			\
	act2.c			\
	init_player.c		\
	keydown.c		\
	map.c			\
	back_to_start.c		\
	main.c			\
	npc.c			\
	windows.c		\
	monster.c		\
	xio.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -ansi -pedantic -I. -Imenu $(shell sdl-config --cflags)
LDFLAGS_Linux	= -lSDLmain $(shell sdl-config --libs) -lSDL_ttf
LDFLAGS_FreeBSD	= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lpthread -lSDL_ttf

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS_$(OSNAME))

all	: $(NAME)

.c.o	: 
	$(CC) $(CFLAGS) -c -o $@ $<

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all