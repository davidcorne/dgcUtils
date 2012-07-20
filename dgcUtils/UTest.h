//=============================================================================
//D Define my own assertion macro so that it can display a message. Put the
//D unit test function I use in this for reuse.

#ifndef UTest_H
#define UTest_H

#include "Assert.h"

//=============================================================================
void utest(const bool test_value, const std::string& message)
//
//D Test the value and return the message with PASSED or FAILED, assert on
//D fail with the message and location.
//
{
  if (!test_value) {
    std::cerr << "FAILED: ";
    assert(test_value, message);
  } else {
    std::cout << "PASSED: " << message << std::endl;
    std::cout << std::endl;
  }
}

//=============================================================================
void print_test_title(const std::string& title)
//
//D Prints the title in the middle of two 79 char banners.
//
{
  std::string banner(79, '=');
  std::cout << std::endl;
  std::cout << banner << std::endl;

  // format the string so that it stays in the lines
  std::string remaining(title);
  while (remaining.length() > 79) {
    int index = 0;
    for (int i = 79; i >= 0; --i) {
      if (remaining[i] == ' ') {
        index = i;
        break;
      }
    }
    for (int i = 0; i < index; ++i) {
      std::cout << remaining[i];
    }
    std::cout << std::endl;
    remaining.erase(remaining.begin(), remaining.begin() + index + 1);
  }
  std::cout << remaining << std::endl;
  
  std::cout << banner << std::endl << std::endl;
}
#endif

