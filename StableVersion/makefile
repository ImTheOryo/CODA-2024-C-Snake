# Makefile

NAME = snake

SRCS = main.c \
	food.c \
	snake.c \
	game.c

SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer
all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME) $(SDL2_CFLAGS) $(SDL2_LDFLAGS) -lm

fclean:
	rm -f $(NAME)

re: fclean all