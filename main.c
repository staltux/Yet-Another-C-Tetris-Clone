#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int InitializeSDL(SDL_Window* window,SDL_Renderer* renderer)
{
    if(SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) != 0)
    {
        SDL_Log("Error in SDL initialization: %s", SDL_GetError());
        return 1;
    }

    if(SDL_CreateWindowAndRenderer(128,128,0,&window,&renderer) != 0)
    {
        SDL_Log("Error creating window or renderer: %s", SDL_GetError());
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    InitializeSDL(window, renderer);

    SDL_RenderClear(renderer);
    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}