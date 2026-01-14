#include "lab2_8.h"
#include <numeric>
#include <iterator>

std::vector<double> list_to_average_vector(const std::list<int>& L) {
  std::vector<double> V;
    
  if (L.size() < 2) {
      return V;
  }
    
  std::adjacent_difference(
      L.begin(), 
      L.end(), 
      std::back_inserter(V), 
      [](int a, int b) { 
          return (static_cast<double>(a) + b) / 2.0; 
      }
  );
    
  V.erase(V.begin());
    
  return V;
}