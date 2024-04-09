cmake_minimum_required(VERSION 3.12)
project(3dVisualizer)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV
find_package(OpenCV REQUIRED)
# Find GLFW
find_package(glfw3 REQUIRED)
# Find OpenGL
find_package(OpenGL REQUIRED)
# Find GLEW
find_package(GLEW REQUIRED)
# Find GLM
find_package(GLM REQUIRED)
# Add the directory containing stb_image.h to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})


set(SOURCE_FILES
    main.cpp
    utils/EBO.cc
    utils/VBO.cc
    utils/VAO.cc
    utils/ShaderClass.cc
    utils/Texture.cc
    utils/Camera.cc
    utils/Mesh.cc
)

# Add executable
add_executable(main ${SOURCE_FILES})

# Include glad.c in the project
add_library(GLAD ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/gl.c)
target_include_directories(GLAD PUBLIC glad/include)

# Link GLFW, OpenGL, and GLEW libraries
target_link_libraries(main PRIVATE glfw OpenGL::GL GLEW::GLEW GLAD ${OpenCV_LIBS})

# Add include directories
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
