cmake_minimum_required(VERSION 3.14)

project(play_with_conan CXX)

find_package(Boost 1.71.0 OPTIONAL_COMPONENTS filesystem unit_test_framework program_options)

if(TARGET Boost::filesystem)
  message("Boost::filesystem is found")
else()
  message("Boost::filesystem was NOT found")
endif()

if(TARGET Boost::unit_test_framework)
  message("Boost::unit_test_framework is found")
else()
  message("Boost::unit_test_framework was NOT found")
endif()

if(TARGET Boost::program_options)
  message("Boost::program_options is found")
else()
  message("Boost::program_options was NOT found")
endif()