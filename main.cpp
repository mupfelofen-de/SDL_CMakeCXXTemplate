#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdlib.h>

int main()
{
    if (0 > SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Could not initialise SDL2: %s %s\n", __func__, SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Hello SDL2",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        320,
        240,
        SDL_WINDOW_SHOWN);

    if (NULL == window)
    {
        SDL_Log("Could not create window: %s %s\n", __func__, SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_Log("Could not create renderer %s %s\n", __func__, SDL_GetError());
        return 1;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
