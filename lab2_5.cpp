#include "lab2_5.h"

void RemoveLastZero(std::deque<int>& D) {
  // ищем последний ноль с конца
  auto r = std::find(D.rbegin(), D.rend(), 0);

  // если нашли ноль
  if (r != D.rend()) {
    // erase принимает обычный итератор
    D.erase((r + 1).base());
  }
}
