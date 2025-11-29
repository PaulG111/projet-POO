cmake_minimum_required(VERSION 4.0)
project(projet_POO)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)

include(FetchContent)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.x
)

FetchContent_MakeAvailable(sfml)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG        v1.89.9
)
FetchContent_MakeAvailable(imgui)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${imgui_SOURCE_DIR})

FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
        GIT_TAG        v2.6
)

FetchContent_MakeAvailable(imgui-sfml)

add_executable(projet_POO
        Cellule.cpp
        main.cpp
        EtatMort.cpp
        EtatVivant.cpp
        Grille.cpp
        Fichier.cpp
        RegleConway.cpp
        Jeu.cpp
        VueConsole.cpp
        VueGraphique.cpp
        IVue.h
)

target_link_libraries(projet_POO PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        ImGui-SFML::ImGui-SFML
)
