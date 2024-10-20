#include "snake.h"

void spawnFood(Food *food) {
    food->type = (rand() %(15 + 1)) ;
    food->position.x = (rand() % (WINDOW_GAME_WIDTH / TILE_SIZE)) * TILE_SIZE;
    food->position.y = (rand() % (WINDOW_GAME_HEIGHT / TILE_SIZE)) * TILE_SIZE;
}

int checkFoodCollision(Snake *snake, Food *food) {
    int x = abs(snake->position->x - food->position.x);
    int y = abs(snake->position->y - food->position.y);
    return (sqrt(x*x)+(y*y) < 8);
}

void drawFood(SDL_Renderer *renderer, Food *food, SDL_Texture *texture) {
    if(food-> type == 3)
    {
        SDL_Rect rectfood = {food->position.x, food->position.y, 32, 32};
        SDL_Rect rect_img_food = {384,0,32, 32};
        SDL_RenderCopy(renderer, texture,&rect_img_food,&rectfood);
    }
    else {
        SDL_Rect rectfood = {food->position.x, food->position.y, 32, 32};
    SDL_Rect rect_img_food = {352,0,32, 32};
    SDL_RenderCopy(renderer, texture,&rect_img_food,&rectfood);
    }

}

