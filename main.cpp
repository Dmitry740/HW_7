
#include "headers.h"

int main(int argc, const char* argv[]) {
  int n{0};
  if (argc > 0 && argc < 3) {
    n = std::stoi(argv[1]);
    example(n);
  } else {
    std::cout << "Error: wrong data" << std::endl;
  }
  return 0;
}
