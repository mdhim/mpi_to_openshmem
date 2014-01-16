cmake_minimum_required (VERSION 2.6)

add_library(pwt pwt.c converse.c workitem.c workq.c scheduler.c workreq.c perfstat.c manager.c worker.c)


find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
set(CMAKE_C_FLAGS ${CMAKE_C_COMPILE_FLAGS} "-Wall -I.. -D_GNU_SOURCE -g" ${MPI_COMPILE_FLAGS})
