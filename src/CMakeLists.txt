#搜索源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)
#生成动态库
add_library(mprpc SHARED ${SRC})



