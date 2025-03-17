
set(SRC ../user.pb.cc calluserservice.cpp)

link_libraries(mprpc)
add_executable(caller ${SRC})
target_link_libraries(caller protobuf)