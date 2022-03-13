cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

<<<<<<< HEAD
add_executable(stack 03-stack/Stack_Array.c)
=======
add_executable(main main.cpp)
>>>>>>> 0c49f27ba82ee4122e9975728f72cb8640e90f43

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
