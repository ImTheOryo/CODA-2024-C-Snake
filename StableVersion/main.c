#include "snake.h"

int main(int argc, char *argv[]) {
     if (SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO) != 0) {
        printf("Erreur lors de l'initialisation de la SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur lors de la création de la fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }


    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        printf("Erreur lors de l'initialisation de SDL_mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }

    // Charger un fichier MP3
    Mix_Music* music = Mix_LoadMUS("musique.mp3");
    if (!music) {
        printf("Erreur lors du chargement du fichier MP3: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }



    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Erreur lors de l'initialisation de l'Image: %s\n", IMG_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur lors de la création du renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Surface *nyancatsurface = IMG_Load("NyanCat.png");
    SDL_Surface *boardsurface = IMG_Load("BoardNyabCat.png");
    if (!nyancatsurface || !boardsurface) {
        printf("Erreur lors du chargement des images: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Texture *nyancattexture = SDL_CreateTextureFromSurface(renderer, nyancatsurface);
    SDL_Texture *boardtexture = SDL_CreateTextureFromSurface(renderer, boardsurface);
    SDL_FreeSurface(boardsurface);
    SDL_FreeSurface(nyancatsurface);

    srand(time(NULL));

    Snake snake;
    Food food;
    initSnake(&snake);
    spawnFood(&food);

    int running = 1;
    SDL_Event event;
    int delay = 100;
    Mix_PlayMusic(music, -1);
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        if (snake.dy == 0) {
                            snake.dx = 0;
                            snake.dy = -TILE_SIZE;
                        }
                        break;
                    case SDLK_DOWN:
                        if (snake.dy == 0) {
                            snake.dx = 0;
                            snake.dy = TILE_SIZE;
                        }
                        break;
                    case SDLK_LEFT:
                        if (snake.dx == 0) {
                            snake.dx = -TILE_SIZE;
                            snake.dy = 0;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (snake.dx == 0) {
                            snake.dx = TILE_SIZE;
                            snake.dy = 0;
                        }
                        break;
                }
            }
        }
        updateSnake(&snake);

        if (isCollision(&snake)) {
            printf("Game Over!\n");
            running = 0;
        }

        if (checkFoodCollision(&snake, &food)) {
            growSnake(&snake,&food);
            spawnFood(&food);
        }

        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        coverBoardWithImage(renderer, boardtexture, WINDOW_WIDTH, WINDOW_HEIGHT, 672, 672);
        drawSnake(renderer, &snake, nyancattexture);
        drawFood(renderer, &food, nyancattexture);

        SDL_RenderPresent(renderer);
        SDL_Delay(delay);
    }

    SDL_DestroyTexture(nyancattexture);
    SDL_DestroyTexture(boardtexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    return 0;
}
