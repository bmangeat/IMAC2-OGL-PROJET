#include <imgui/include/imgui.h>
#include <imgui/include/imgui_impl_opengl3.h>
#include <imgui/include/imgui_impl_sdl.h>
#include "SDL.h"

#include <string>

#include "../include/Interface.hpp"


Interface::Interface(SDL_Window *window, SDL_GLContext *context)
        : glsl_version("#version 330 core") {

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
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

void Interface::DrawInterface(SDL_Window *window, Cursor worldCursor, Grid worldGrid, glm::vec3 attribColor) const {


    static bool popup_save = false;
    static bool popup_open = false;



    ImGuiIO &io = ImGui::GetIO();
    ImGuiStyle &style = ImGui::GetStyle();
    ImGuiWindowFlags window_flags = 0;


    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open...", "CTRL+O", &popup_open)) {}
            if (ImGui::MenuItem("Save", "CTRL+S", &popup_save)) {}
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);

    // Main body of the Demo window starts here.
    if (ImGui::Begin("Editor", NULL, window_flags))
    {
        if (ImGui::Button("Add/delete"))
        {
            if (worldCursor.getSelect() == 1) {
                worldGrid.AddCube(worldCursor.getCursorPosition(), attribColor);
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Select"))
        {}
        ImGui::SameLine();
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
    }

/*
    static int counter = 0;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    bool light = true;
    // Menu_ bar
    *//*
     * 0 = no popup window will be opened
     * 1 = Popup open
     * 2 = Popup save
     *
     * *//*

    int menu_bar = 0;




    // Create a window called "Editor" and append into it.

    // Append a menu bar with several features
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {

                // TODO : Open popup "Open file"
                menu_bar = 1;


            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) {

                // TODO : Open popup "Save file"

                menu_bar = 2;

            }
            if (ImGui::MenuItem("Close", "Ctrl+W")) {

                // TODO : Close the windows

                SDL_DestroyWindow(window);

            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if (menu_bar == 1) { ImGui::OpenPopup("Open"); }
    if (menu_bar == 2) { ImGui::OpenPopup("Save"); }

    if(ImGui::BeginPopup("Open")) {
        ImGui::Text("Load your file : ");
    }

    if(ImGui::BeginPopup("Save")) {
        ImGui::Text("Save your file : ");
    }


    ImVec2 window_pos = ImVec2(0,0);

    ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always);


    if (ImGui::Begin(
            "Editor", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {
        ImGui::SetWindowSize(ImVec2(400, 400));



        ImGui::Text("Manage your cubes : ");
        if (ImGui::Button(
                "Add"))
            counter++;
        ImGui::SameLine();

        if (ImGui::Button(
                "Delete"))
            counter++;
        ImGui::SameLine();

        if (ImGui::Button(
                "Select"))
            counter++;
        ImGui::SameLine();

        if (ImGui::Button(
                "Extrude"))
            counter++;
        ImGui::SameLine();

        if (ImGui::Button(
                "Dig"))
            counter++;

        ImGui::NewLine();
        ImGui::TextWrapped("Color:");
        ImGui::ColorEdit3("Color cube", (float *) &clear_color); // Edit 3 floats representing a color

        ImGui::NewLine();

        ImGui::TextWrapped("Light:");
        ImGui::Checkbox("Switch the light ", &light);


    }
    ImGui::End();*/
}

void Interface::RenderInterface() const {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
