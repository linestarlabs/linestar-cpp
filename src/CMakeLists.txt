add_executable(linestar_api main.cpp LinestarController.cpp)

target_include_directories(linestar_api PRIVATE ../include)
target_link_libraries(linestar_api PRIVATE pistache pthread)

