#include "SDL_Wrappers.h"

void SCION_UTILS::SDL_Destroyer::operator()(SDL_Window *window) const {
    SDL_DestroyWindow(window);
    std::cout << "detroyed SDL window\n";
}

void SCION_UTILS::SDL_Destroyer::operator()([[maybe_unused]] const SDL_GameController *controller) const noexcept {}

void SCION_UTILS::SDL_Destroyer::operator()([[maybe_unused]] const SDL_Cursor *cursor) const noexcept {}

// static Controller make_shared_controller([[maybe_unused]] const SDL_GameController *controller) { return Controller(); }
// static Cursor make_shared_cursor([[maybe_unused]] const SDL_Cursor *cursor) { return Cursor(); }
