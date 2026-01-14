#include "lab2_9.h"
#include <algorithm>
#include <set>

int count_vectors_containing_all(const std::vector<int>& V0, 
                                 const std::vector<std::vector<int>>& vectors) {
  int count = 0;
    
  if (V0.empty()) {
      return 0;
  }
    
  // Создаем множество из элементов V0 (удаляем дубликаты)
  std::set<int> setV0(V0.begin(), V0.end());
    
  // Проверяем каждый вектор из набора
  for (const auto& vec : vectors) {
      // Создаем множество из элементов текущего вектора
      std::set<int> currentSet(vec.begin(), vec.end());
        
      // Проверяем, содержит ли currentSet все элементы из setV0
      bool containsAll = std::includes(
          currentSet.begin(), currentSet.end(),
          setV0.begin(), setV0.end()
      );
        
      if (containsAll) {
          ++count;
      }
  }
    
  return count;
}