#pragma once

#include <imgui/include/imgui.h>
#include <imgui/include/imgui_impl_opengl3.h>
#include <imgui/include/imgui_impl_sdl.h>
#include "SDL.h"
#include "cursor.hpp"
#include "Grid.hpp"


class Interface {
private:
    const char *glsl_version;
public:

    //! Constructor
    /*!
      \brief Initialize imgui window and some presets
      \param window Refer to SDL window
      \param context Refer to context of our window
    */
    Interface(SDL_Window* window, SDL_GLContext* context);

    //! Destructor
    /*!
      \brief Delete context from imgui window
    */
    ~Interface();

    //! Interface Initiliazer
    /*!
      \brief Initialize first frame of imgui window
      \param window Refer to SDL window
    */
    void CreateInterface(SDL_Window* window) const;

    //! Draw Initiliazer
    /*!
      \brief Create imgui's windows
      \param window Refer to SDL window
      \param worldCursor Refer to cursor of the scene
      \param worldGrid Refer to grid of the scene
      \param attribColor Vector of colors

    */
    void DrawInterface(SDL_Window* window, Cursor &worldCursor, Grid &worldGrid, glm::vec3 attribColor) const;

    //! Draw Initiliazer
    /*!
      \brief Render imgui's windows
    */
    void RenderInterface() const;

};