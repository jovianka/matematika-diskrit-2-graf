cmake_minimum_required(VERSION 3.22.1)

project(Graph1)

# EXTERNAL LIBRARIES
# find_package(Curses REQUIRED)
# set(CURSES_PANEL_INCLUDE_PATH, "/usr/include/panel.h")
# add_link_options(-lpanel -lmenu -lncurses)

# LIBRARIES
add_library(graph STATIC graph.c)

add_executable(project1 main.c)

# target_include_directories(project1 PUBLIC ${CURSES_INCLUDE_DIRS} ${CURSES_MENU_INCLUDE_PATH} ${CURSES_PANEL_INCLUDE_PATH})

target_link_libraries(project1 graph)