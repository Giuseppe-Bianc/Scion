#pragma once
#include <ScionUtilities/SDL_Wrappers.h>

namespace SCION_WINDOWING {
    class Window {
    public:
        Window() : Window("default_window", 640, 480, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, true, NULL) {}
        Window(const std::string title, int width, int heigt, int x_pos, int y_pos, bool v_sync = true,
               Uint32 flags = (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MOUSE_CAPTURE));
        ~Window() = default;
        inline void SetGLContex(SDL_GLContext gl_context) noexcept { m_GLContext = gl_context; }
        inline SDL_GLContext &GetGLContex() noexcept { return m_GLContext; }
        inline WindowPtr &GetWindow() noexcept { return m_pWindow; }
        inline const std::string &GetWindowName() const noexcept { return m_sTitle; }
        inline const int GetXPos() const noexcept { return m_XPos; }
        inline void SetXPos(int x_pos) noexcept { m_XPos = x_pos; }
        inline const int GetYPos() const noexcept { return m_YPos; }
        inline void SetYPos(int y_pos) noexcept { m_YPos = y_pos; }
        inline const int GetWidth() const noexcept { return m_Width; }
        inline void SetWidth(int width) noexcept { m_Width = width; }
        inline const int GetHeigt() const noexcept { return m_Heigt; }
        inline void SetHeigt(int heigt) noexcept { m_Heigt = heigt; }
        void SetWindowName(const std::string &name) noexcept;

    private:
        WindowPtr m_pWindow;
        SDL_GLContext m_GLContext;
        std::string m_sTitle;
        int m_Width, m_Heigt, m_XPos, m_YPos;
        Uint32 m_WindowFlags;
        void CreateNewWindow(Uint32 flags);
    };
}  // namespace SCION_WINDOWING
