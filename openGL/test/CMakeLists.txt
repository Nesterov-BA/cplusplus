cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

set(CMAKE_CXX_STANDARD 17)

# Находим пакеты
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Добавляем исполняемый файл (не забудьте включить glad.c)
add_executable(MyOpenGLApp src/main.cpp src/glad.c)
# Указываем пути к заголовкам GLAD (если нужно)
target_include_directories(MyOpenGLApp PRIVATE src/include)

# Линкуем библиотеки
target_link_libraries(MyOpenGLApp OpenGL::GL glfw)
