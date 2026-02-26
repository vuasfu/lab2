#include "functions.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric> 


// Заполнение сначала второй, а потом первой половиной вектора
void task1(const std::vector<int>& V) {
  size_t mid = V.size() / 2;

  for (std::vector<int>::const_iterator it = V.cbegin() + mid; it != V.cend(); ++it) {
      std::cout << *it << " ";
  }
  for (std::vector<int>::const_iterator it = V.cbegin(); it != V.cbegin() + mid; ++it) {
      std::cout << *it << " ";
  }
}

// Вставить после 5 элемента списка первые 5 элементов вектора в обратном порядке
void task2(const std::vector<int>& V, std::list<int>& L) {
  auto iter_list = std::next(L.begin(), 5);
  std::vector<int> left_side(V.begin(), V.begin() + 5);
  L.insert(iter_list, left_side.rbegin(), left_side.rend());

  std::cout << "Список L: ";
  for (std::list<int>::const_iterator it = L.cbegin(); it != L.cend(); ++it) {
    std::cout << *it << " ";
  }
}

// Поменять первую и вторую половину местами
void task3(std::list<int>& L1, std::list<int>& L2) {
  auto L1_mid = std::next(L1.begin(), (L1.size() / 2));
  auto L2_mid = std::next(L2.begin(), (L2.size() / 2));
  auto L1_begin = L1.begin(); // Сохранение списка

  L1.splice(L1.begin(), L2, L2_mid, L2.end());
  L2.splice(L2.end(), L1, L1_begin, L1_mid);

  std::cout << "Список 1: ";
  for (std::list<int>::const_iterator it = L1.cbegin(); it != L1.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "Список 2: ";
  for (std::list<int>::const_iterator it = L2.cbegin(); it != L2.cend(); ++it) {
    std::cout << *it << " ";
  }
}

// Записать из 1 файла во второй файл все слова, которые не больше K
void task4(int K, const std::string& name1, const std::string& name2) {
  std::ifstream input(name1);
  std::ofstream output(name2);

  if (!input.is_open() || !output.is_open()) {
    std::cerr << "Невозможно открыть файл\n";
    return;
  }

  std::istream_iterator<std::string> begin(input);
  std::istream_iterator<std::string> end;
  std::ostream_iterator<std::string> out(output, "\n");

  std::remove_copy_if(
    begin,
    end,
    out,
    [K](const std::string& word) {
      return word.size() > K;
    });
}

// Удалить последний нулевой элемент дека
void task5(std::deque<int>& D) {
  auto r = std::find(D.rbegin(), D.rend(), 0);
  D.erase(std::prev(r.base()));

  std::cout << "Дек после изменения: ";
  for (std::deque<int>::const_iterator it = D.cbegin(); it != D.cend(); ++it){
    std::cout << *it << " ";
  }
}

// Добавить в начало каждого вектора 5 элементов со значениями A, а в конец — 5 элементов со значениями B
void task6(int A, int B, std::vector<int>& V1, std::vector<int>& V2) {

  std::fill_n(inserter(V1, V1.begin()), 5, A);
  std::fill_n(back_inserter(V1), 5, B);

  V2.insert(V2.begin(), 5, A);
  V2.insert(V2.end(), 5, B);

  std::cout << "Вектор V1 после изменений: ";
  for (std::vector<int>::const_iterator it = V1.cbegin(); it != V1.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "Вектор V2 после изменений: ";
  for (std::vector<int>::const_iterator it = V2.cbegin(); it != V2.cend(); ++it) {
    std::cout << *it << " ";
  }
}

// Сортировка 2 половины и слияние
void task7(std::vector<int>& V) {
  auto mid = std::next(V.begin(), (V.size() / 2));

  bool sorted = std::is_sorted(V.begin(), mid);
  if (!sorted) {
    std::cerr << "Первая половина должна быть уже отсортирована.\n";
    return;
  }

  std::sort(mid, V.end());

  std::inplace_merge(V.begin(), mid, V.end());
  std::cout << "Вектор после сортировки и слияния: ";
  for (auto it = V.cbegin(); it != V.cend(); ++it) {
    std::cout << *it << " ";
  }
}

// Среднее арифметическое всех пар
void task8(std::list<int>& L, std::vector<double>& V) {
  V.clear();
  std::adjacent_difference(
    L.begin(),
    L.end(),
    std::back_inserter(V),
    [](int a, int b) {
      return (a + b) / 2.0;
    });

  V.erase(V.begin()); // Удаляем лишний первый элемент
  std::cout << "Вектор средних значений: ";
  for (auto it = V.cbegin(); it != V.cend(); ++it) {
    std::cout << *it << " ";
  }
}

// Найти количество векторов VI, I = 1, …, N, в которых содержатся все элементы вектора V0 
int task9(std::vector<int>& V0, std::vector<std::vector<int>>& vectors) {
  std::set<int> set0(V0.begin(), V0.end());
  int count = 0;
  for (auto it = vectors.begin(); it != vectors.end(); ++it) {
    const std::vector<int>& Vi = *it;
    std::set<int> set_i(Vi.begin(), Vi.end());
    if (std::includes(set_i.begin(), set_i.end(), set0.begin(), set0.end())) {
      ++count;
    }
  }
  return count;
}

// Определить суммарную длину слов по букве и вывести все буквы
void task10(const std::vector<std::string>& V) {
  std::map<char, int> M;
  for (auto it = V.cbegin(); it != V.cend(); ++it) {
    if (it->empty()) {
      continue;
    }
    char first = (*it)[0];
    M[first] += it->size();
  }

  std::cout << "Результат:\n";
  for (auto it = M.cbegin(); it != M.cend(); ++it) {
    std::cout << it->first << " " << it->second << "\n";
  }
}
