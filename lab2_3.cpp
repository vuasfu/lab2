#include "lab2_3.h"
#include <list>
#include <iterator>
#include <iostream>

void peremeshenie(std::list<int>& L1, std::list<int>& L2) {
  // Создаем копии
  std::list<int> copy1 = L1;
  std::list<int> copy2 = L2;
    
  // Очищаем оригиналы
  L1.clear();
  L2.clear();
    
  // Вставляем вторую половину L2 в L1
  auto it = copy2.begin();
  std::advance(it, copy2.size() / 2);
  for (; it != copy2.end(); ++it) {
      L1.push_back(*it);
  }
    
  // Вставляем вторую половину исходного L1 в L1
  it = copy1.begin();
  std::advance(it, copy1.size() / 2);
  for (; it != copy1.end(); ++it) {
      L1.push_back(*it);
  }
    
  // Вставляем первую половину L2 в L2
  it = copy2.begin();
  for (size_t i = 0; i < copy2.size() / 2; ++i) {
      L2.push_back(*it);
      ++it;
  }
    
  // Вставляем первую половину L1 в L2
  it = copy1.begin();
  for (size_t i = 0; i < copy1.size() / 2; ++i) {
      L2.push_back(*it);
      ++it;
  }
    
  // Вывод
  std::cout << "\nПосле обмена (обратный порядок):\n";
  std::cout << "L1: ";
  for (auto rit = L1.rbegin(); rit != L1.rend(); ++rit) {
      std::cout << *rit << " ";
  }
  std::cout << "\nL2: ";
  for (auto rit = L2.rbegin(); rit != L2.rend(); ++rit) {
      std::cout << *rit << " ";
  }
  std::cout << "\n";
}