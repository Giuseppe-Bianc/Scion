#define SDL_MAIN_HANDLED 1;
// clang-format off
#include <Windoing/Window/Window.h>
#include <SDL.h>
#include <glad/glad.h>
//clang-format on

int main() {
    bool running{true};
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::string error = SDL_GetError();
        std::cout << std::format("failed to initialize SDL: {}\n", error);
        running = false;
        return -1;
    }
    if(SDL_GL_LoadLibrary(NULL) != 0) {
        std::string error = SDL_GetError();
        std::cout << std::format("failed to open GL library: {}\n", error);
        running = false;
        return -1;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    SCION_WINDOWING::Window window("test_window", 640, 480, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, true,
                                   SDL_WINDOW_OPENGL);
    if(!window.GetWindow()) {
        std::cout << "falied to create window" << std::endl;
        running = false;
        return -1;
    }
    window.SetGLContex(SDL_GL_CreateContext(window.GetWindow().get()));
    if(!window.GetGLContex()) {
        std::string error = SDL_GetError();
        std::cout << std::format("falied to create gl context: {}\n", error);
        running = false;
        return -1;
    }
    SDL_GL_MakeCurrent(window.GetWindow().get(), window.GetGLContex());
    SDL_GL_SetSwapInterval(1);
    if(gladLoadGLLoader(SDL_GL_GetProcAddress) == 0) {
        std::cout << "failed to loadGL --> GLAD" << std::endl;
        running = false;
        return -1;
    }
    SDL_Event event{};
    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    running = false;
                break;
            default:
                break;
            }
        }
        glViewport(window.GetXPos(), window.GetYPos(), window.GetWidth(), window.GetHeigt());
        glClearColor(0.f, 0.f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window.GetWindow().get());
    }
    std::cout << "Quitting\n"; 
    SDL_Quit();
    return 0;
}
