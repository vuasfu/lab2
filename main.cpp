#include "functions.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <limits>
#include <locale>
#include <stdexcept>

namespace {

void ClearInputStream() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Проверка, что вводится число
bool ReadInt(int& value, const std::string& prompt) {
  std::cout << prompt;
  if (std::cin >> value) {
    return true;
  }
  ClearInputStream();
  std::cerr << "Ошибка: необходимо ввести целое число!\n";
  return false;
}

// Проверка на позитивное число
bool ReadPositiveInt(int& value, const std::string& prompt) {
  if (!ReadInt(value, prompt)){
    return false;
  }
  if (value > 0) {
    return true;
  }
  std::cerr << "Ошибка: значение должно быть положительным!\n";
  return false;
}

// Проверка на наименьшее заданное 
bool ReadIntWithMin(int& value, const std::string& prompt, int min_value) {
  if (!ReadInt(value, prompt)){
    return false;
  }
  if (value >= min_value) {
    return true;
  } 
  std::cerr << "Ошибка: значение должно быть не меньше " << min_value << "!\n";
  return false;
}

// Чётное положительное число
bool ReadEvenInt(int& value, const std::string& prompt) {
  if (!ReadInt(value, prompt)) {
    return false;
  }
  if (value <= 0) {
    std::cerr << "Ошибка: значение должно быть положительным!\n";
    return false;
  }
  if (value % 2 == 0) {
    return true;
  } 
  std::cerr << "Ошибка: значение должно быть четным!\n";
  return false;
}

//  Шаблон для заполнения контейнера
template <typename Container>
bool ReadContainer(Container& container, int size, const std::string& type_name) {
  if (size <= 0) {
    std::cerr << "Ошибка: размер контейнера должен быть положительным!\n";
    return false;
  }
  std::cout << "Введите " << size << " целых чисел для " << type_name << ":\n";
  for (int i = 0; i < size; ++i) {
    std::cout << "  Элемент " << (i + 1) << ": ";
    int x;
    if (!(std::cin >> x)) {
      ClearInputStream();
      std::cerr << "Ошибка ввода на позиции " << i + 1 << "\n";
      return false;
    }
    container.push_back(x);
  }
  return true;
}

// Проверка на ввод строки
bool ReadString(std::string& value, const std::string& prompt) {
  std::cout << prompt;
  if (std::cin >> value){
    return true;
  } 
  ClearInputStream();
  std::cerr << "Ошибка ввода строки!\n";
  return false;
}

// Вывод задачи
void PrintTaskHeader(int task_number, const std::string& title,
                     const std::string& description) {
  std::cout << "\nЗАДАЧА " << task_number << ": " << title << "\n";
  
  std::string desc = description;
  size_t pos = 0;
  while (pos < desc.length()) {
    size_t new_pos = desc.find('\n', pos);
    if (new_pos == std::string::npos) {
      std::cout << "  " << desc.substr(pos) << "\n";
      break;
    }
    std::cout << "  " << desc.substr(pos, new_pos - pos) << "\n";
    pos = new_pos + 1;
  }
}

} 

int main() {
  try {
    std::locale::global(std::locale(""));
    std::cout.imbue(std::locale());
    std::cin.imbue(std::locale());
    std::cerr.imbue(std::locale());
  } catch (...) {
  }

  int choice = -1;

  while (true) {
    std::cout << "\n1 - Задача 1: Вывод половин вектора\n";
    std::cout << "2 - Задача 2: Вставка элементов вектора в список\n";
    std::cout << "3 - Задача 3: Обмен половинами списков\n";
    std::cout << "4 - Задача 4: Фильтрация слов по длине в файле\n";
    std::cout << "5 - Задача 5: Удаление последнего нуля из дека\n";
    std::cout << "6 - Задача 6: Добавление элементов в векторы\n";
    std::cout << "7 - Задача 7: Сортировка и слияние половин вектора\n";
    std::cout << "8 - Задача 8: Средние арифметические пар элементов\n";
    std::cout << "9 - Задача 9: Поиск векторов-надмножеств\n";
    std::cout << "10 - Задача 10: Суммарная длина слов по первой букве\n";
    std::cout << "0 - Выход\n";
    std::cout << "Выберите задачу (0-10): ";

    if (!(std::cin >> choice)) {
      if (std::cin.eof()) {
        std::cout << "\nДостигнут конец файла. Завершение программы.\n";
        break;
      }
      ClearInputStream();
      std::cerr << "Ошибка: необходимо ввести число от 0 до 10!\n";
      continue;
    }

    if (choice == 0) {
      std::cout << "Программа завершена.\n";
      break;
    }

    if (choice < 0 || choice > 10) {
      std::cerr << "Ошибка: неверный номер задачи. Выберите от 0 до 10.\n";
      continue;
    }

    try {
      switch (choice) {
        case 1: {
          PrintTaskHeader(1, "Вывод половин вектора",
            "Дан набор целых чисел с четным количеством элементов.\n"
            "Заполнить вектор V исходными числами, вывести вначале вторую половину\n"
            "элементов вектора V, а затем первую половину (в каждой половине\n"
            "порядок элементов не изменять).");
          
          int n;
          if (!ReadEvenInt(n, "Размер вектора (четное число): ")) {
            break;
          }
          
          std::vector<int> V;
          if (ReadContainer(V, n, "вектора")) {
            std::cout << "\nРезультат: ";
            task1(V);
            std::cout << "\n";
          }
          break;
        }
        
        case 2: {
          PrintTaskHeader(2, "Вставка элементов вектора в список",
            "Даны вектор V и список L. Каждый исходный контейнер содержит не менее 5\n"
            "элементов. Вставить после элемента списка с порядковым номером 5 первые\n"
            "5 элементов вектора в обратном порядке. Использовать один вызов\n"
            "функции-члена insert.");
          
          int n, m;
          if (!ReadIntWithMin(n, "Размер вектора (не менее 5): ", 5)) {
            break;
          }
          
          std::vector<int> V;
          if (!ReadContainer(V, n, "вектора")) {
            break;
          }
          
          if (!ReadIntWithMin(m, "Размер списка (не менее 5): ", 5)) {
            break;
          }
          
          std::list<int> L;
          if (ReadContainer(L, m, "списка")) {
            std::cout << "\nРезультат:\n";
            task2(V, L);
            std::cout << "\n";
          }
          break;
        }
        
        case 3: {
          PrintTaskHeader(3, "Обмен половинами списков",
            "Даны списки L1 и L2, имеющие четное количество элементов.\n"
            "Поменять местами первую половину исходного списка L1 и вторую половину\n"
            "исходного списка L2. Использовать два вызова функции-члена splice.");
          
          int n, m;
          if (!ReadEvenInt(n, "Размер списка L1 (четное число): ")) {
            break;
          }
          
          std::list<int> L1;
          if (!ReadContainer(L1, n, "списка L1")) {
            break;
          }
          
          if (!ReadEvenInt(m, "Размер списка L2 (четное число): ")) {
            break;
          }
          
          std::list<int> L2;
          if (ReadContainer(L2, m, "списка L2")) {
            std::cout << "\nРезультат:\n";
            task3(L1, L2);
            std::cout << "\n";
          }
          break;
        }
        
        case 4: {
          PrintTaskHeader(4, "Фильтрация слов по длине в файле",
            "Дано целое число K (> 0), текстовый файл с именем name1, содержащий\n"
            "английские слова, и строка name2. Записать в текстовый файл с именем name2\n"
            "все слова из исходного файла, длина которых не превосходит K, сохранив\n"
            "исходный порядок их следования и располагая каждое слово на новой строке.\n"
            "Использовать алгоритм remove_copy_if.");
          
          int K;
          if (!ReadPositiveInt(K, "Введите максимальную длину слова (K > 0): ")) {
            break;
          }
          
          std::string name1, name2;
          if (!ReadString(name1, "Введите имя входного файла: ")) {
            break;
          }
          if (ReadString(name2, "Введите имя выходного файла: ")) {
            task4(K, name1, name2);
            std::cout << "\nГотово! Результат сохранен в файл \"" << name2 << "\"\n";
          }
          break;
        }
        
        case 5: {
          PrintTaskHeader(5, "Удаление последнего нуля из дека",
            "Дан дек D. Удалить последний нулевой элемент дека. Если нулевых элементов\n"
            "нет, то дек не изменять. Использовать алгоритм find с обратными итераторами\n"
            "и функцию-член erase. Алгоритм find возвращает обратный итератор, функция\n"
            "base() позволяет перейти к обычному итератору.");
          
          int n;
          if (!ReadPositiveInt(n, "Размер дека: ")) {
            break;
          }
          
          std::deque<int> D;
          if (ReadContainer(D, n, "дека")) {
            std::cout << "\nРезультат:\n";
            task5(D);
            std::cout << "\n";
          }
          break;
        }
        
        case 6: {
          PrintTaskHeader(6, "Добавление элементов в векторы",
            "Даны числа A и B и векторы V1 и V2. Добавить в начало каждого вектора 5\n"
            "элементов со значениями A, а в конец — 5 элементов со значениями B.\n"
            "При преобразовании вектора V1 использовать два вызова алгоритма fill_n с\n"
            "функциями inserter и back_inserter. При преобразовании вектора V2\n"
            "использовать два вызова функции-члена insert.");
          
          int A, B;
          if (!ReadInt(A, "Введите значение A: ")) {
            break;
          }
          if (!ReadInt(B, "Введите значение B: ")) {
            break;
          }
          
          int n1, n2;
          if (!ReadPositiveInt(n1, "Размер вектора V1: ")) {
            break;
          }
          if (!ReadPositiveInt(n2, "Размер вектора V2: ")) {
            break;
          }
          
          std::vector<int> V1;
          if (!ReadContainer(V1, n1, "вектора V1")) {
            break;
          }
          
          std::vector<int> V2;
          if (ReadContainer(V2, n2, "вектора V2")) {
            std::cout << "\nРезультат:\n";
            task6(A, B, V1, V2);
            std::cout << "\n";
          }
          break;
        }
        
        case 7: {
          PrintTaskHeader(7, "Сортировка и слияние половин вектора",
            "Дан вектор V с четным количеством элементов. Известно, что первая половина\n"
            "вектора уже отсортирована по возрастанию. Отсортировать все элементы\n"
            "вектора по возрастанию, выполнив вначале сортировку его второй половины\n"
            "алгоритмом sort, а затем слияние обеих половин алгоритмом inplace_merge.\n"
            "Выводить содержимое вектора V после применения каждого алгоритма.");
          
          int n;
          if (!ReadEvenInt(n, "Размер вектора (четное число): ")) {
            break;
          }
          
          std::vector<int> V;
          if (ReadContainer(V, n, "вектора")) {
            std::cout << "\nРезультат:\n";
            task7(V);
            std::cout << "\n";
          }
          break;
        }
        
        case 8: {
          PrintTaskHeader(8, "Средние арифметические пар элементов",
            "Дан список L. Получить вектор V вещественных чисел, содержащий значения\n"
            "среднего арифметического для всех пар соседних элементов исходного списка.\n"
            "Количество элементов вектора V должно быть на 1 меньше количества\n"
            "элементов списка L. Например: список [1, 3, 4, 6] → вектор [2.0, 3.5, 5.0].\n"
            "Использовать алгоритм adjacent_difference с итератором вставки и\n"
            "функциональным объектом, а также функцию-член erase.");
          
          int n;
          std::cout << "Размер списка (минимум 2 элемента): ";
          if (!(std::cin >> n)) {
            ClearInputStream();
            std::cerr << "Ошибка: необходимо ввести число!\n";
            break;
          }
          
          if (n < 2) {
            std::cerr << "Ошибка: размер списка должен быть не меньше 2!\n";
            break;
          }
          
          std::list<int> L;
          std::cout << "Введите " << n << " целых чисел для списка:\n";
          bool input_success = true;
          for (int i = 0; i < n; ++i) {
            std::cout << "  Элемент " << (i + 1) << ": ";
            int x;
            if (!(std::cin >> x)) {
              ClearInputStream();
              std::cerr << "Ошибка ввода на позиции " << i + 1 << "\n";
              input_success = false;
              break;
            }
            L.push_back(x);
          }
          
          if (input_success) {
            std::vector<double> V;
            task8(L, V);
          }
          std::cout << "\n";
          break;
        }
        
        case 9: {
          PrintTaskHeader(9, "Поиск векторов-надмножеств",
            "Дан вектор V0 и набор векторов V1, ..., VN. Размер V0 не превосходит размера\n"
            "любого из векторов V1, ..., VN. Найти количество векторов VI, которые\n"
            "содержат все элементы вектора V0 (без учета повторений). Использовать\n"
            "алгоритм includes, применяя его к множествам, созданным на основе векторов.");
          
          int n;
          if (!ReadPositiveInt(n, "Размер вектора V0: ")) {
            break;
          }
          
          std::vector<int> V0;
          if (!ReadContainer(V0, n, "вектора V0")) {
            break;
          }
          
          int k;
          if (!ReadPositiveInt(k, "Количество векторов для проверки: ")) {
            break;
          }
          
          std::vector<std::vector<int>> vectors;
          bool success = true;
          
          for (int i = 0; i < k; ++i) {
            int sz;
            std::cout << "\nВектор #" << i + 1 << ":\n";
            if (!ReadIntWithMin(sz, "  Размер вектора: ",
                                static_cast<int>(V0.size()))) {
              success = false;
              break;
            }
            
            std::vector<int> temp;
            if (!ReadContainer(temp, sz, "вектора #" + std::to_string(i + 1))) {
              success = false;
              break;
            }
            vectors.push_back(temp);
          }
          
          if (success) {
            int result = task9(V0, vectors);
            std::cout << "Результат: " << result << " из " << k
                     << " векторов содержат все элементы V0\n";
          }
          break;
        }
        
        case 10: {
          PrintTaskHeader(10, "Суммарная длина слов по первой букве",
            "Дан вектор V, элементами которого являются английские слова, набранные\n"
            "ЗАГЛАВНЫМИ буквами. Определить суммарную длину слов, начинающихся с одной\n"
            "и той же буквы. Вывести буквы в алфавитном порядке и суммарную длину.\n"
            "Использовать отображение map, операции индексирования [] и size().\n"
            "Условные конструкции при заполнении отображения не использовать.");
          
          int n;
          if (!ReadPositiveInt(n, "Количество слов: ")) {
            break;
          }
          
          std::vector<std::string> V(n);
          std::cout << "Введите " << n << " слов ЗАГЛАВНЫМИ английскими буквами:\n";
          bool success = true;
          
          for (int i = 0; i < n; ++i) {
            std::cout << "  Слово " << i + 1 << ": ";
            if (!(std::cin >> V[i])) {
              ClearInputStream();
              std::cerr << "Ошибка ввода слова!\n";
              success = false;
              break;
            }
          }
          
          if (success) {
            std::cout << "\nРезультат:\n";
            task10(V);
          }
          break;
        }
      }
    } catch (const std::bad_alloc& e) {
      std::cerr << "\nКритическая ошибка: недостаточно памяти!\n";
      ClearInputStream();
    } catch (const std::exception& e) {
      std::cerr << "\nОшибка выполнения: " << e.what() << "\n";
      ClearInputStream();
    } catch (...) {
      std::cerr << "\nНеизвестная ошибка!\n";
      ClearInputStream();
    }
  }
  
  return 0;
}