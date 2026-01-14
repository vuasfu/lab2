#include "lab2_4.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

void FilterWords(int K, const std::string& name1, const std::string& name2) {
  // Сначала получаем слова от пользователя
  std::vector<std::string> words;
  std::string word;
  
  std::cout << "Введите слова (для завершения введите 'end'):\n";
  std::cout << "Слово 1: ";
  int counter = 1;
  
  while (std::cin >> word && word != "end") {
    words.push_back(word);
    counter++;
    std::cout << "Слово " << counter << ": ";
  }
  
  // Записываем в файл
  std::ofstream fout(name1);
  for (const auto& w : words) {
    fout << w << " ";
  }
  fout.close();
  
  std::cout << "Слова записаны в файл '" << name1 << "'\n";
  
  // Теперь фильтруем
  std::ifstream fin(name1);
  std::ofstream fout2(name2);
  
  if (!fin.is_open() || !fout2.is_open()) {
    std::cout << "Ошибка открытия файлов!\n";
    return;
  }
  
  std::istream_iterator<std::string> in(fin);
  std::istream_iterator<std::string> end;
  
  std::ostream_iterator<std::string> out(fout2, " ");
  
  std::remove_copy_if(in, end, out, [K](const std::string& w) { 
    return w.length() > K; 
  });
  
  fin.close();
  fout2.close();
  
  // Читаем и выводим результат
  std::ifstream result(name2);
  std::cout << "\nОтфильтрованные слова из файла '" << name2 << "': ";
  
  std::string filtered_word;
  bool first = true;
  while (result >> filtered_word) {
    if (!first) std::cout << " ";
    std::cout << filtered_word;
    first = false;
  }
  
  if (first) {
    std::cout << "(нет слов подходящей длины)";
  }
  
  std::cout << "\n";
}