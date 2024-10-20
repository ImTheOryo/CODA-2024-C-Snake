#include "snake.h"

void initSnake(Snake *snake) {
    snake->length = 5;
    snake->dx = TILE_SIZE;
    snake->dy = 0;
    for (int i = 0; i < snake->length; i++) {
        snake->position[i].x = WINDOW_GAME_WIDTH / 2 - i * TILE_SIZE;
        snake->position[i].y = WINDOW_GAME_HEIGHT / 2;
    }
}

void drawSnake(SDL_Renderer *renderer, Snake *snake, SDL_Texture *nyancattexture) {
    for (int i = 0; i < snake->length; i++) {
        SDL_Rect dest_rect = {snake->position[i].x, snake->position[i].y, 32, 32};

        if (i == 0) {

            SDL_Rect rect_img_head;

            if (snake->dx > 0) {

                rect_img_head = (SDL_Rect){32, 0, 32, 32};
            } else if (snake->dx < 0) {

                rect_img_head = (SDL_Rect){64, 0, 32, 32};
            } else if (snake->dy > 0) {
                rect_img_head = (SDL_Rect){128, 0, 32, 32};
            } else if (snake->dy < 0) {

                rect_img_head = (SDL_Rect){96, 0, 32, 32};
            }


            SDL_RenderCopy(renderer, nyancattexture, &rect_img_head, &dest_rect);
        }
        else if (i == snake->length - 1) {

            Point prev = snake->position[i - 1];
            Point next = snake->position[i + 1];

            if (prev.x == snake->position[i].x && next.x == snake->position[i].x)
            {

                SDL_Rect rect_img_body = {192, 0, 32, 32};
                SDL_RenderCopy(renderer, nyancattexture, &rect_img_body, &dest_rect);
            }
            else if (prev.y == snake->position[i].y && next.y == snake->position[i].y)
            {
                SDL_Rect rect_img_body = {160, 0, 32, 32};
                SDL_RenderCopy(renderer, nyancattexture, &rect_img_body, &dest_rect);
            }
            else {
                SDL_Rect rect_img_corner;
                if ((prev.x > snake->position[i].x && next.y > snake->position[i].y) ||
                    (next.x > snake->position[i].x && prev.y > snake->position[i].y)) {
                    rect_img_corner = (SDL_Rect){288, 0, 32, 32};
                    } else if ((prev.x > snake->position[i].x && next.y < snake->position[i].y) ||
                               (next.x > snake->position[i].x && prev.y < snake->position[i].y)) {
                        rect_img_corner = (SDL_Rect){224, 0, 32, 32};
                               } else if ((prev.x < snake->position[i].x && next.y > snake->position[i].y) ||
                                          (next.x < snake->position[i].x && prev.y > snake->position[i].y)) {
                                   rect_img_corner = (SDL_Rect){320, 0, 32, 32};
                                          } else if ((prev.x < snake->position[i].x && next.y < snake->position[i].y) ||
                                                     (next.x < snake->position[i].x && prev.y < snake->position[i].y)) {
                                              rect_img_corner = (SDL_Rect){256, 0, 32, 32};
                                                     }
            }
        }
        else {

            Point prev = snake->position[i - 1];
            Point next = snake->position[i + 1];

            if (prev.x == snake->position[i].x && next.x == snake->position[i].x)
                 {

                SDL_Rect rect_img_body = {192, 0, 32, 32};
                SDL_RenderCopy(renderer, nyancattexture, &rect_img_body, &dest_rect);
            }
            else if (prev.y == snake->position[i].y && next.y == snake->position[i].y)
              {
                  SDL_Rect rect_img_body = {160, 0, 32, 32};
                  SDL_RenderCopy(renderer, nyancattexture, &rect_img_body, &dest_rect);
              }
            else {

                SDL_Rect rect_img_corner;
                if ((prev.x > snake->position[i].x && next.y > snake->position[i].y) ||
                    (next.x > snake->position[i].x && prev.y > snake->position[i].y)) {
                    rect_img_corner = (SDL_Rect){288, 0, 32, 32};
                } else if ((prev.x > snake->position[i].x && next.y < snake->position[i].y) ||
                           (next.x > snake->position[i].x && prev.y < snake->position[i].y)) {
                    rect_img_corner = (SDL_Rect){224, 0, 32, 32};
                } else if ((prev.x < snake->position[i].x && next.y > snake->position[i].y) ||
                           (next.x < snake->position[i].x && prev.y > snake->position[i].y)) {
                    rect_img_corner = (SDL_Rect){320, 0, 32, 32};
                } else if ((prev.x < snake->position[i].x && next.y < snake->position[i].y) ||
                           (next.x < snake->position[i].x && prev.y < snake->position[i].y)) {
                    rect_img_corner = (SDL_Rect){256, 0, 32, 32};
                }
                SDL_RenderCopy(renderer, nyancattexture, &rect_img_corner, &dest_rect);
            }
        }
    }
}

void updateSnake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->position[i] = snake->position[i - 1];
    }
    snake->position[0].x += snake->dx;
    snake->position[0].y += snake->dy;
}

void growSnake(Snake *snake,Food *food) {
    if(food->type == 3)
    {
            snake -> length ++;
        snake -> length ++;
        snake -> length ++;

    }
    else
    {
        snake-> length ++;
    }
}


