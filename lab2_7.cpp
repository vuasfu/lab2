#include "lab2_7.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

std::vector<int> read_vector() {
  std::vector<int> v;
  int n;
  
  std::cin >> n;
  
  if (n % 2 != 0) {
    std::cerr << "Ошибка: количество элементов должно быть четным" << std::endl;
    exit(1);
  }
  
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  
  return v;
}

void print_vector(const std::vector<int>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void sort_vector(std::vector<int>& v) {
  if (v.empty()) {
    return;
  }
  
  if (v.size() % 2 != 0) {
    std::cout << "Ошибка: количество элементов должно быть четным" << std::endl;
    return;
  }
  
  size_t half = v.size() / 2;
  
  // Проверяем, что первая половина отсортирована по возрастанию
  bool is_sorted = true;
  for (size_t i = 1; i < half; ++i) {
    if (v[i] < v[i - 1]) {
      is_sorted = false;
      break;
    }
  }
  
  if (!is_sorted) {
    std::cout << "Ошибка: первая половина вектора не отсортирована по возрастанию!" << std::endl;
    return; // Только одна ошибка, без предупреждения
  }
  
  std::cout << "Исходный вектор: ";
  print_vector(v);
  
  // Сортируем вторую половину
  std::sort(v.begin() + half, v.end());
  
  std::cout << "После sort второй половины: ";
  print_vector(v);
  
  // Объединяем
  std::inplace_merge(v.begin(), v.begin() + half, v.end());
  
  std::cout << "После inplace_merge: ";
  print_vector(v);
}