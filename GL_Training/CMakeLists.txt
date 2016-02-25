cmake_minimum_required(VERSION 3.4)
project(GL_Training)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp include/Tester.hpp src/Tester.cpp)
add_executable(GL_Training ${SOURCE_FILES})

### My Includes ####
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)


### GLEW ###
set(GLEW_DIR ${PROJECT_SOURCE_DIR}/external/glew)

### GLFW ###
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/external/glfw-3.1.2)
add_subdirectory(${GLFW_DIR})
set(ALL_LIBRARIES ${ALL_LIBRARIES} glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})

# ADD THEM TOGETHER
set(EXTERNAL_INCLUDE_DIRS ${GLEW_DIR}/include ${GLFW_DIR}/include)

set(ALL_DIRECTORIES ${EXTERNAL_INCLUDE_DIRS} ${PROJECT_INCLUDE_DIR})
include_directories(${ALL_DIRECTORIES})


### LIBRARIES ###
set(GLEW_LIBRARIES ${GLEW_DIR}/bin/Release/x64/glew32.dll)
set(ALL_LIBRARIES ${GLEW_LIBRARIES} glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})

target_link_libraries(GL_Training ${ALL_LIBRARIES})
#add_executable(main main.c)
#target_link_libraries(main A)

find_package(GLUT)
find_package(OpenGL)
if (OPENGL_FOUND)
    MESSAGE("OpenGL Correctly Found")
    include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
    MESSAGE("OpenGL environment missing")
endif (OPENGL_FOUND)


### GLFW ###
#set(GLFW_DIR ${PROJECT_EXT_DIR}/glfw-3.1.2)
#set(EXTERNAL_INCLUDE_DIRS ${EXTERNAL_INCLUDE_DIRS} ${GLFW_DIR}/include)
#set(ALL_LIBRARIES ${ALL_LIBRARIES} glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
### add_subdirectory(${GLFW_DIR})
