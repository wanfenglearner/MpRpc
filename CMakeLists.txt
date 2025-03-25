#cmake最低版本
cmake_minimum_required(VERSION 3.0)
#项目名称
project(Mprpc)
#构建Debug环境
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
#设置lib文件生成目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
#设置可生成文件的生成目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

#库文件的搜索路径
link_directories(/usr/local/lib ${CMAKE_SOURCE_DIR}/lib)

#头文件搜索路径
include_directories(${CMAKE_SOURCE_DIR}/example)
include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/src)

#存放mprpc框架的目录
add_subdirectory(src)
#存放使用mprpc框架的目录(调用者与被调用者的目录)
add_subdirectory(example)



