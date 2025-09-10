#include <chrono>

auto start = std::chrono::steady_clock::now();
// 작업 수행
auto end = std::chrono::steady_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
