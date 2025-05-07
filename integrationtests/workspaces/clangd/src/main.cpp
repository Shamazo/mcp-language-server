#include <iostream>

// FooBar is a simple function for testing
void foo_bar() {
  std::cout << "Hello, World!" << std::endl;
  return;
}

int main() {
  return 0;

  // Intentional error: unreachable code
  std::cout << "This is unreachable" << std::endl;
}