cmake_minimum_required(VERSION 3.14)

project(play_with_conan CXX)

find_package(Eigen3 3.1.0)

if(TARGET Eigen3::Eigen)
  message("Eigen3 is found")
else()
  message("Eigen3 was NOT found")
endif()