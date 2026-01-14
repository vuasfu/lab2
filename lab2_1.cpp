#include "lab2_1.h"
#include <iostream>

void DelVector(const std::vector<int> & V) {
  std::vector<int> result;

  auto mid = V.begin() + V.size() / 2;

  for (auto it = mid; it !=V.end(); ++it){
    result.push_back(*it);
  }
  for (auto it = V.begin(); it !=mid; ++it){
    result.push_back(*it);
  }
  std::cout << "Результат: ";
  for (int x : result) std::cout << x << " ";
  std::cout << "\n";
}  