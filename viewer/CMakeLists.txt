include_directories(./include)

# GLFW Load
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
link_directories(${GLFW_BINARY_DIR}/src)
include_directories(../glfw/include)
file(GLOB VIEWER_INCLUDE_FILE ./include/*.hpp)
file(GLOB VIEWER_SRC_FILE ./src/*.cpp)

# Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED filesystem system)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(./src)
