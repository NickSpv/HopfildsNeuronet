cmake_minimum_required(VERSION 3.23)
project(HopfildsNeuronet)

set(CMAKE_CXX_STANDARD 17)

add_executable(HopfildsNeuronet main.cpp Neuronet.tpp Neuronet.h RealNumber.cpp RealNumber.h constants.h)
