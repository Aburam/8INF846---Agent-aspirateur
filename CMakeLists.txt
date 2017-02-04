cmake_minimum_required(VERSION 3.6)
project(8INF846-TP1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Environnement.cpp Carte.cpp Case.cpp Poussiere.cpp )


set(HEADERS Environnement.h Carte.h Case.h Poussiere.h )
add_executable(8INF846-TP1 ${SOURCE_FILES} ${HEADER})