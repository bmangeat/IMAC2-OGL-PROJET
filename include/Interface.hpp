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
    Interface(SDL_Window* window, SDL_GLContext* context);

    ~Interface();

    void CreateInterface(SDL_Window* window) const;

    void DrawInterface(SDL_Window* window, Cursor worldCursor, Grid worldGrid, glm::vec3 attribColor) const;

    void RenderInterface() const;

};