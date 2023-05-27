#include "headers.h"

void print(const std::vector<std::string>& queue) {
  if (queue.empty()) {
    return;
  }
  long long res_time{0};
  std::string filename;

  std::cout << "bulk: ";
  if (queue.size() > 0) {
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t q = 0; q != queue.size(); ++q) {
      if (q == 0) {
        auto w = queue[q];

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_ms =
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        res_time = elapsed_ms.count();
        filename = "bulk" + std::to_string(res_time) + ".log";
      }
      std::ofstream out_file{filename, std::ios_base::app};
      if (!out_file) {
        std::cout << "Failed to open file: " << filename << std::endl;
      }
      std::cout << queue[q];
      out_file << queue[q];
      if (q != queue.size() - 1) {
        std::cout << ", ";
        out_file << ", ";
      }
    }
  }
}

void DynamicCase(State& state, std::vector<std::string>& queue, const int& n) {
  int m{0};
  size_t dyn = 1;
  while (std::cin && state == State::Dynamic) {
    std::string command;
    std::cin >> command;
    if (command == "{") {
      ++dyn;
      m = 0;
    }
    if (command == "}") {
      --dyn;
    }
    if (command != "{" && command != "}" && std::cin) {
      if (m < n && dyn > 0) {
        queue.push_back(command);
        ++m;
      }
    }
    if (m == (n + 1) || dyn == 0) {
      print(queue);
      queue.clear();
      m = 0;
      state = State::Static;
      StaticCase(n);
    }
  }
}
void StaticCase(int n) {
  std::vector<std::string> queue;
  State state = State::Static;

  std::string command;
  int m{0};

  while (std::cin && state == State::Static) {
    std::cin >> command;
    if (m < n && command != "{" && std::cin) {
      queue.push_back(command);
      ++m;
    }
    if (m < n && command != "{" && !std::cin) {
      print(queue);
      queue.clear();
      m = 0;
    }
    if (m == n && command != "{") {
      print(queue);
      queue.clear();
      m = 0;
    }
    if (m < n && command == "{") {
      print(queue);
      queue.clear();
      m = 0;
      state = State::Dynamic;
      DynamicCase(state, queue, n);
    }
  }
}

void example(int n) { StaticCase(n); }