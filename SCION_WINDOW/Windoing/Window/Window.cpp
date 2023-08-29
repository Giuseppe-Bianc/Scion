#include "Window.h"

namespace SCION_WINDOWING {
    Window::Window(const std::string title, int width, int heigt, int x_pos, int y_pos, bool v_sync, Uint32 flags)
        : m_pWindow(nullptr), m_GLContext{}, m_sTitle(title), m_Width(width), m_Heigt(heigt), m_XPos(x_pos), m_YPos(y_pos),
          m_WindowFlags(flags) {
        CreateNewWindow(flags);
        if(v_sync && !SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
            std::cout << "failed to enable VSYNC\n";
        }
        std::cout << "window created sucsefuly\n";
    }

    // Window::~Window() {}

    void Window::SetWindowName(const std::string &name) noexcept {
        m_sTitle = name;
        SDL_SetWindowTitle(m_pWindow.get(), name.c_str());
    }

    void Window::CreateNewWindow(Uint32 flags) {
        m_pWindow = WindowPtr(SDL_CreateWindow(m_sTitle.c_str(), m_XPos, m_YPos, m_Width, m_Heigt, flags));
        if(!m_pWindow) {
            std::string error = SDL_GetError();
            std::cout << std::format("failed to create window {}\n", error);
        }
    }
}  // namespace SCION_WINDOWING
