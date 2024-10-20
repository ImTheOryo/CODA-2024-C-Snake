#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define WINDOW_WIDTH 672
#define WINDOW_GAME_WIDTH 640
#define WINDOW_HEIGHT 672
#define WINDOW_GAME_HEIGHT 640
#define TILE_SIZE 32

//Les structs utilisé
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position[100];
    int length;
    int dx;
    int dy;
} Snake;

typedef struct {
    int type;
    Point position;
} Food;
//game.c
bool isCollision(Snake *snake);
bool isWin(int snakeLen);
void coverBoardWithImage(SDL_Renderer *renderer, SDL_Texture *texture, int window_width, int window_height, int tile_width, int tile_height);

//snake.c
void initSnake(Snake *snake);
void drawSnake(SDL_Renderer *renderer, Snake *snake, SDL_Texture *texture);
void updateSnake(Snake *snake);
void growSnake(Snake *snake, Food *food);

//food.c
void spawnFood(Food *food);
void drawFood(SDL_Renderer *renderer, Food *food, SDL_Texture *texture);
int checkFoodCollision(Snake *snake, Food *food);

#endif
