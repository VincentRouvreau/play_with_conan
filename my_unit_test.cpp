#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "my_unit_test"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(my_basic_unit_test) {
  std::clog << "********************************************************************" << std::endl;
  std::clog << "BASIC UNIT TEST" << std::endl;

  // Should be ok
  BOOST_CHECK(true);
}
