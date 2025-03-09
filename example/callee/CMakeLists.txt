
#搜索源文件
set(SRC userservice.cpp ../user.pb.cc)

add_executable(provider ${SRC})
target_link_libraries(provider mprpc protobuf)