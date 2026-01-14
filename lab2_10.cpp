#include "lab2_10.h"
#include <iostream>
#include <map>

void process_words(const std::vector<std::string>& V) {
  // Вспомогательное отображение: ключ - первая буква, значение - суммарная длина
  std::map<char, int> M;
    
  // Заполняем отображение M
  // Используем итератор для перебора вектора V
  for (auto it = V.begin(); it != V.end(); ++it) {
    const std::string& word = *it;
        
    if (!word.empty()) {
        char first_letter = word[0];
        // Используем операцию индексирования []
        // Если ключа нет, он создается с нулевым значением
        M[first_letter] += word.size(); // Инкрементируем суммарную длину
    }
}
    
// Выводим результаты
// Используем итератор для перебора отображения M
for (auto it = M.begin(); it != M.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
}
}