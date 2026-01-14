#include "lab2_2.h"

void razvorot( std::vector<int>& V, std::list<int>& L){
  // Создаем временный вектор, чтобы развернуть его  
  std::vector<int> demo_vector(V.rbegin(), V.rend()); 
  
  // Берём первые
  auto start = demo_vector.rbegin();
  auto end = demo_vector.rbegin() + 5;

  auto fifth_element = L.begin();
  std::advance(fifth_element, 5);
  L.insert(fifth_element, start, end);
}