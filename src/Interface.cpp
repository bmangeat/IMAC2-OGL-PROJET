#include <imgui/include/imgui.h>
#include <imgui/include/imgui_impl_opengl3.h>
#include <imgui/include/imgui_impl_sdl.h>
#include "SDL.h"

#include "../include/Interface.h"


Interface::Interface(SDL_Window *window, SDL_GLContext *context)
        : glsl_version("#version 330 core") {

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
/*    ImGuiIO &io = ImGui::GetIO();
    (void) io;*/
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

Interface::~Interface() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void Interface::CreateInterface(SDL_Window *window) const {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
}

void Interface::DrawInterface(SDL_Window *window) const {

    static float f = 0.0f;
    static int counter = 0;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    // Create a window called "Editor" and append into it.
    if (ImGui::Begin("Editor")) {

        // Append a menu bar with several features
        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open..", "Ctrl+O")) {

                    // TODO : Open save fonctionnality

                }
                if (ImGui::MenuItem("Save", "Ctrl+S")) {

                    // TODO : Save our world fonctionnality

                }
                if (ImGui::MenuItem("Close", "Ctrl+W")) {

                    // TODO : Close the windows

                    SDL_DestroyWindow(window);

                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)


        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float *) &clear_color); // Edit 3 floats representing a color

        if (ImGui::Button(
                "Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                    1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
    }
    ImGui::End();
}

void Interface::RenderInterface() const {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
