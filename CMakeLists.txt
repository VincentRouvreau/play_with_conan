cmake_minimum_required(VERSION 3.14)

project(play_with_conan CXX)

find_package(Boost 1.71.0 OPTIONAL_COMPONENTS unit_test_framework)

if(TARGET Boost::unit_test_framework)
  message("Boost::unit_test_framework is found")
else()
  message("Boost::unit_test_framework was NOT found")
endif()

enable_testing()

add_executable ( my_unit_test my_unit_test.cpp )
target_link_libraries(my_unit_test Boost::unit_test_framework)
add_test(NAME my_unit_test COMMAND $<TARGET_FILE:my_unit_test>)