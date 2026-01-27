#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <fstream>
#include <cstdlib>
#include <locale>

#include "lab2_1.h"
#include "lab2_2.h"
#include "lab2_3.h"
#include "lab2_4.h"
#include "lab2_5.h"
#include "lab2_6.h"
#include "lab2_7.h"
#include "lab2_8.h"
#include "lab2_9.h"
#include "lab2_10.h"



// Вспомогательные функции для ввода
template<typename T>
T InputWithCheck(const std::string& prompt) {
  T value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      break;
    } else {
      std::cout << "Ошибка ввода! Пожалуйста, введите корректное значение.\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }
  return value;
}

void Task1() {
  std::cout << "\nЗадание 1\n";
  std::cout << "Создание вектора из второй и первой половин исходного вектора\n\n";
  
  int n = InputWithCheck<int>("Введите количество элементов вектора: ");
  
  std::vector<int> V(n);
  std::cout << "Введите " << n << " элементов вектора:\n";
  for (int i = 0; i < n; ++i) {
    V[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  std::cout << "Исходный вектор: ";
  for (int x : V) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  DelVector(V);
}

void Task2() {
  std::cout << "\nЗадание 2\n";
  std::cout << "Вставка последних 5 элементов развернутого вектора в список после 5-го элемента\n\n";
  
  // Создаем вектор
  int n = InputWithCheck<int>("Введите количество элементов вектора (>=5): ");
  if (n < 5) {
    std::cout << "Вектор должен содержать не менее 5 элементов!\n";
    return;
  }
  
  std::vector<int> V(n);
  std::cout << "Введите " << n << " элементов вектора:\n";
  for (int i = 0; i < n; ++i) {
    V[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  // Создаем список
  int m = InputWithCheck<int>("Введите количество элементов списка (>=5): ");
  if (m < 5) {
    std::cout << "Список должен содержать не менее 5 элементов!\n";
    return;
  }
  
  std::list<int> L;
  std::cout << "Введите " << m << " элементов списка:\n";
  for (int i = 0; i < m; ++i) {
    int val = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
    L.push_back(val);
  }
  
  std::cout << "\nИсходный вектор: ";
  for (int x : V) {
    std::cout << x << " ";
  }
  
  std::cout << "\nИсходный список: ";
  for (int x : L) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  razvorot(V, L);
  
  std::cout << "Список после вставки: ";
  for (int x : L) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void Task3() {
  std::cout << "\nЗадание 3\n";
  std::cout << "Обмен первой половиной L1 со второй половиной L2\n\n";
  
  // Ввод первого списка
  int n1 = InputWithCheck<int>("Введите количество элементов первого списка: ");
  std::list<int> L1;
  std::cout << "Введите " << n1 << " элементов первого списка:\n";
  for (int i = 0; i < n1; ++i) {
    int val = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
    L1.push_back(val);
  }
  
  // Ввод второго списка
  int n2 = InputWithCheck<int>("Введите количество элементов второго списка: ");
  std::list<int> L2;
  std::cout << "Введите " << n2 << " элементов второго списка:\n";
  for (int i = 0; i < n2; ++i) {
    int val = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
    L2.push_back(val);
  }
  
  std::cout << "\nИсходный L1: ";
  for (int x : L1) {
    std::cout << x << " ";
  }
  std::cout << "\nИсходный L2: ";
  for (int x : L2) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  peremeshenie(L1, L2);
  
  // Дополнительный вывод для проверки
  std::cout << "\nПроверка (прямой порядок):\n";
  std::cout << "L1: ";
  for (int x : L1) {
    std::cout << x << " ";
  }
  std::cout << "\nL2: ";
  for (int x : L2) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void Task4() {
  std::cout << "\nЗадание 4\n";
  std::cout << "Фильтрация слов длиной не более K\n\n";
  
  int K = InputWithCheck<int>("Введите максимальную длину слова K: ");
  
  // Создаем тестовый файл
  std::string filename1 = "input_words.txt";
  std::string filename2 = "output_words.txt";
  
  std::ofstream fout(filename1);
  fout << "Hello World C++ Programming Algorithm Iterator Vector List";
  fout.close();
  
  std::cout << "Создан файл '" << filename1 << "' с тестовыми словами\n";
  
  FilterWords(K, filename1, filename2);
  
  std::cout << "Результат записан в файл '" << filename2 << "'\n";
  
  // Читаем и выводим результат
  std::ifstream fin(filename2);
  std::string word;
  std::cout << "Отфильтрованные слова: ";
  while (fin >> word) {
    std::cout << word << " ";
  }
  std::cout << "\n";
}

void Task5() {
  std::cout << "\nЗадание 5\n";
  std::cout << "Удаление последнего нуля из дека\n\n";
  
  int n = InputWithCheck<int>("Введите количество элементов дека: ");
  
  std::deque<int> D;
  std::cout << "Введите " << n << " элементов дека (могут быть нули):\n";
  for (int i = 0; i < n; ++i) {
    int val = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
    D.push_back(val);
  }
  
  std::cout << "Исходный дек: ";
  for (int x : D) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  RemoveLastZero(D);
  
  std::cout << "Дек после удаления последнего нуля: ";
  for (int x : D) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void Task6() {
  std::cout << "\nЗадание 6\n";
  std::cout << "Добавление элементов в векторы\n\n";
  
  int A = InputWithCheck<int>("Введите значение A: ");
  int B = InputWithCheck<int>("Введите значение B: ");
  
  // Ввод вектора V1
  int n1 = InputWithCheck<int>("Введите количество элементов в векторе V1: ");
  std::vector<int> V1(n1);
  std::cout << "Введите " << n1 << " элементов вектора V1:\n";
  for (int i = 0; i < n1; ++i) {
    V1[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  // Ввод вектора V2
  int n2 = InputWithCheck<int>("Введите количество элементов в векторе V2: ");
  std::vector<int> V2(n2);
  std::cout << "Введите " << n2 << " элементов вектора V2:\n";
  for (int i = 0; i < n2; ++i) {
    V2[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  std::cout << "\nИсходные векторы:\n";
  std::cout << "V1: ";
  for (int x : V1) {
    std::cout << x << " ";
  }
  std::cout << "\nV2: ";
  for (int x : V2) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  AddElements(A, B, V1, V2);
  
  std::cout << "\nПосле добавления:\n";
  std::cout << "V1: ";
  for (int x : V1) {
    std::cout << x << " ";
  }
  std::cout << "\nV2: ";
  for (int x : V2) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void Task7() {
  std::cout << "\nЗадание 7\n";
  std::cout << "Сортировка вектора (первая половина уже отсортирована)\n\n";
  
  int n = InputWithCheck<int>("Введите четное количество элементов: ");
  while (n % 2 != 0) {
    std::cout << "Количество должно быть четным! Введите снова: ";
    n = InputWithCheck<int>("");
  }
  
  std::vector<int> V(n);
  std::cout << "Введите элементы (первая половина должна быть отсортирована по возрастанию):\n";
  
  for (int i = 0; i < n; ++i) {
    V[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  sort_vector(V);
}

void Task8() {
  std::cout << "\nЗадание 8\n";
  std::cout << "Средние значения соседних элементов списка\n\n";
  
  int n = InputWithCheck<int>("Введите количество элементов списка (>=2): ");
  while (n < 2) {
    std::cout << "Должно быть не менее 2 элементов! Введите снова: ";
    n = InputWithCheck<int>("");
  }
  
  std::list<int> L;
  std::cout << "Введите " << n << " элементов списка:\n";
  for (int i = 0; i < n; ++i) {
    int val = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
    L.push_back(val);
  }
  
  std::cout << "Исходный список: ";
  for (int x : L) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  
  std::vector<double> V = list_to_average_vector(L);
  
  std::cout << "Вектор средних значений: ";
  for (double x : V) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void Task9() {
  std::cout << "\nЗадание 9\n";
  std::cout << "Поиск векторов, содержащих все элементы V0\n\n";
  
  // Создаем V0
  int n0 = InputWithCheck<int>("Введите количество элементов в V0: ");
  std::vector<int> V0(n0);
  std::cout << "Введите " << n0 << " элементов V0:\n";
  for (int i = 0; i < n0; ++i) {
    V0[i] = InputWithCheck<int>("Элемент " + std::to_string(i + 1) + ": ");
  }
  
  // Создаем набор векторов
  int N = InputWithCheck<int>("Введите количество векторов N (>0): ");
  while (N <= 0) {
    std::cout << "N должно быть >0! Введите снова: ";
    N = InputWithCheck<int>("");
  }
  
  std::vector<std::vector<int>> vectors(N);
  
  for (int i = 0; i < N; ++i) {
    // Ввод размера вектора - должен быть >= n0
    int ni = n0; // По умолчанию равен n0
    std::cout << "Введите количество элементов в векторе V" << (i + 1) 
              << " (должно быть >= " << n0 << "): ";
    
    while (true) {
      ni = InputWithCheck<int>("");
      if (ni >= n0) {
        break;
      }
      std::cout << "Размер должен быть >= " << n0 << "! Введите снова: ";
    }
    
    vectors[i].resize(ni);
    std::cout << "Введите " << ni << " элементов вектора V" << (i + 1) << ":\n";
    for (int j = 0; j < ni; ++j) {
      vectors[i][j] = InputWithCheck<int>("Элемент " + std::to_string(j + 1) + ": ");
    }
  }
  
  int count = count_vectors_containing_all(V0, vectors);
  
  std::cout << "\nКоличество векторов, содержащих все элементы V0: " << count << "\n";
}

void Task10() {
  std::cout << "\nЗадание 10\n";
  std::cout << "Суммарная длина слов, начинающихся с одной буквы\n\n";
  
  int n = InputWithCheck<int>("Введите количество английских слов: ");
  
  std::vector<std::string> V(n);
  std::cout << "Введите " << n << " английских слов (будут преобразованы в верхний регистр):\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "Слово " << std::to_string(i + 1) << ": ";
    std::string word;
    std::cin >> word;
    
    // Преобразуем в верхний регистр
    for (char& c : word) {
      c = std::toupper(static_cast<unsigned char>(c));
    }
    
    V[i] = word;
  }
  
  std::cout << "\nСлова в верхнем регистре: ";
  for (const auto& word : V) {
    std::cout << word << " ";
  }
  std::cout << "\n";
  
  std::cout << "\nРезультат (буква и суммарная длина):\n";
  process_words(V);
}

int main() {
  try {
    std::locale::global(std::locale(""));
    std::cout.imbue(std::locale());
  } catch (...) {
  }

  std::cout << "Лабораторная работа 2\n";
  std::cout << "Выполнение всех заданий\n";
  
  int choice;
  do {
    std::cout << "Меню выбора задания:\n";
    std::cout << "1. Задание 1\n";
    std::cout << "2. Задание 2\n";
    std::cout << "3. Задание 3\n";
    std::cout << "4. Задание 4\n";
    std::cout << "5. Задание 5\n";
    std::cout << "6. Задание 6\n";
    std::cout << "7. Задание 7\n";
    std::cout << "8. Задание 8\n";
    std::cout << "9. Задание 9\n";
    std::cout << "10. Задание 10\n";
    std::cout << "0. Выход\n";
    
    choice = InputWithCheck<int>("Выберите задание (0-10): ");
    
    switch (choice) {
      case 1:
        Task1();
        break;
      case 2:
        Task2();
        break;
      case 3:
        Task3();
        break;
      case 4:
        Task4();
        break;
      case 5:
        Task5();
        break;
      case 6:
        Task6();
        break;
      case 7:
        Task7();
        break;
      case 8:
        Task8();
        break;
      case 9:
        Task9();
        break;
      case 10:
        Task10();
        break;
      case 0:
        std::cout << "Выход из программы.\n";
        break;
      default:
        std::cout << "Неверный выбор! Попробуйте снова.\n";
    }
    
  } while (choice != 0);
  
  return 0;

}
