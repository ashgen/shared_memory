cmake_minimum_required(VERSION 3.14)
project(sharedMemory)


set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost 1.45.0 REQUIRED system filesystem program_options iostreams)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()
add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} Threads::Threads rt )
target_link_libraries(client ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} Threads::Threads rt )
