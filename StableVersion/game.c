#include "snake.h"

//Retourne vrai si le serpent prend tout le terain (aucune case n'est vide en gros)
// /!\ En revanche attention à ne pas oublié de compté la tete
bool isWin(int snakeLen) {
    return snakeLen == WINDOW_GAME_WIDTH * WINDOW_GAME_HEIGHT;
}

bool isCollision(Snake *snake) {
    // Collision avec les bords
    if (snake->position[0].x < 0 || snake->position[0].x >= WINDOW_GAME_WIDTH ||
        snake->position[0].y < 0 || snake->position[0].y >= WINDOW_GAME_HEIGHT) {
        return true;
        }

    // Collision avec soi-même
    for (int i = 1; i < snake->length; i++) {
        if (snake->position[0].x == snake->position[i].x &&
            snake->position[0].y == snake->position[i].y) {
            return true;
            }
    }
    return false;
}

void coverBoardWithImage(SDL_Renderer *renderer, SDL_Texture *texture, int window_width, int window_height, int tile_width, int tile_height) {
    SDL_Rect dest_rect;


    for (int y = 0; y < window_height; y += tile_height) {
        for (int x = 0; x < window_width; x += tile_width) {
            dest_rect.x = x;
            dest_rect.y = y;
            dest_rect.w = tile_width;
            dest_rect.h = tile_height;
            SDL_Rect rect_img_back = {0,0,32, 32};

            SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
        }
    }
}