#pragma once

#include "headers.h"
#include <SDL.h>
namespace SCION_UTILS {
    struct SDL_Destroyer {
        void operator()(SDL_Window *window) const;
        void operator()([[maybe_unused]] const SDL_GameController *controller) const noexcept;
        void operator()([[maybe_unused]] const SDL_Cursor *cursor) const noexcept;
    };
}  // namespace SCION_UTILS

using Controller = std::shared_ptr<SDL_GameController>;
// static Controller make_shared_controller([[maybe_unused]] const SDL_GameController *controller);

using Cursor = std::shared_ptr<SDL_Cursor>;
// static Cursor make_shared_cursor([[maybe_unused]] const SDL_Cursor *cursor);

using WindowPtr = std::unique_ptr<SDL_Window, SCION_UTILS::SDL_Destroyer>;
