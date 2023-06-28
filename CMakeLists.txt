cmake_minimum_required(VERSION 3.25)
set(root FFMPEG_EASY)

project(${root})

set(CMAKE_CXX_STANDARD 17)

# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 动态库文件目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 可执行文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#定义源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src sources)
set(FFMPEG ./include/ffmpeg)
include_directories(${FFMPEG})
#加载lib库
file(GLOB LIBNAMES ${CMAKE_CURRENT_SOURCE_DIR}/libs/*.lib)
#引入项目头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(${root} ${sources})
target_link_libraries(${root} PRIVATE ${LIBNAMES})
