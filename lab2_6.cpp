#include "lab2_6.h"

void AddElements(int A, int B, std::vector<int>& V1, std::vector<int>& V2) {
  std::fill_n(std::inserter(V1, V1.begin()), 5, A);

  std::fill_n(std::back_inserter(V1), 5, B);
    
  V2.insert(V2.begin(), 5, A);
  V2.insert(V2.end(), 5, B);
}
