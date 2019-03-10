cmake_minimum_required(VERSION 2.8.4)
project(simpleloggerforcxx)

find_package(Threads REQUIRED)

include_directories(include)

add_library(${PROJECT_NAME} SHARED log/logger.cpp)

#add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
