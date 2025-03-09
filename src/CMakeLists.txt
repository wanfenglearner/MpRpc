#搜索源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

#链接muduo网络库的静态库文件
link_libraries(muduo_net muduo_base)
#生成动态库
add_library(mprpc SHARED ${SRC})
#链接pthread动态库
target_link_libraries(mprpc pthread)

