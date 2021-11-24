#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

static void sdlWindowTest(void)
{
    printf("sdl-window-test\n");
    SDL_Init(SDL_INIT_EVERYTHING);

    int flags = SDL_WINDOW_INPUT_GRABBED;
    SDL_Window *window = SDL_CreateWindow("SDL Window Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, flags);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    int grabbed = true;
    int relative = true;
    int visible = false;

    bool running = true;
    SDL_Event event;
    while (running)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            printf("Quit event\n");
            running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_q)
            {
                printf("User pressed Q -> Quit\n");
                running = false;
            }
            else if (event.key.keysym.sym == SDLK_g)
            {
                // SDL_bool grabbed = SDL_GetWindowGrab(window);
                grabbed = !grabbed;
                printf("User pressed G -> Grab input: %d\n", grabbed);
                SDL_SetWindowGrab(window, grabbed);
            }
            else if (event.key.keysym.sym == SDLK_m)
            {
                // SDL_bool enabled = SDL_GetRelativeMouseMode();
                relative = !relative;
                printf("User pressed M -> Set relative mouse mode: %d\n", relative);
                SDL_SetRelativeMouseMode(relative);
            }
            else if (event.key.keysym.sym == SDLK_c)
            {
                // int visible = SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE;
                visible = !visible;
                printf("User pressed C -> Show cursor: %d\n", visible);
                SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
            }
            break;
        }
    }
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    sdlWindowTest();
    return 0;
}
