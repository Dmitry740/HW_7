#pragma once
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum class State { Static, Dynamic };

void example(int n);

void StaticCase(int n);

void DynamicCase(State& state, std::vector<std::string>& queue, const int& n);

void print(const std::vector<std::string>& queue);