cmake_minimum_required(VERSION 3.6)
project(8INF846-TP1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-pthread")

set(SOURCE_FILES main.cpp Environnement.cpp Agent.cpp Effecteur.cpp Carte.cpp Case.cpp Poussiere.cpp )

set(HEADERS Environnement.h Agent.h Effecteur.h Carte.h Case.h Poussiere.h )
add_executable(8INF846-TP1 ${SOURCE_FILES} ${HEADER})