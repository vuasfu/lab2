# lab2
# ФИО: Булгакова Юлия Олеговна

# Постановка задач

В заданиях 1, 2, 3 элементами контейнеров являются целые числа. Для заполнения контейнера
использовать итератор и конструктор соответствующего контейнера, для вывода элементов
использовать итератор (для вывода элементов в обратном порядке использовать обратные
итераторы, возвращаемые функциями-членами rbegin и rend).
В задании 4 обработка данных выполняется без использования контейнеров. Если алгоритм требует
применения функционального объекта, следует использовать лямбда-выражения. Использовать
итераторы istream_iterator и ostream_iterator.
Если в заданиях 5, 6, 7, 8, 9, 10 тип элементов контейнера не указан, то предполагается, что
элементами являются целые числа.

# Задание 1

Вывести вначале вторую половину элементов вектора, а затем первую половину.

1. Запросить у пользователя четное число n.
2. Создать вектор V и заполнить его n целыми числами.
3. Найти середину вектора: size_t mid = V.size() / 2.
4. Вывести элементы от mid до конца.
5. Вывести элементы от начала до mid.

Реализация

```cpp
void task1(const std::vector<int>& V) {
  size_t mid = V.size() / 2;

  for (std::vector<int>::const_iterator it = V.cbegin() + mid; it != V.cend(); ++it) {
    std::cout << *it << " ";
  }
  for (std::vector<int>::const_iterator it = V.cbegin(); it != V.cbegin() + mid; ++it) {
    std::cout << *it << " ";
  }
}
```
# Тестирование
<img width="519" height="139" alt="image" src="https://github.com/user-attachments/assets/ae87974f-a9a5-401a-921c-66d362d8451b" />
<img width="517" height="238" alt="image" src="https://github.com/user-attachments/assets/f7439097-e10d-4efc-b71c-d36f986e9464" />

# Задание 2

Вставить после 5 элемента списка первые 5 элементов вектора в обратном порядке.

1. Запросить размеры вектора и списка (не менее 5).
2. Заполнить вектор V и список L.
3. Найти итератор на 5-й элемент списка: std::next(L.begin(), 5).
4. Создать вектор left_side с первыми 5 элементами V.
5. Вставить left_side в обратном порядке в список через insert.

Реализация
```cpp
void task2(const std::vector<int>& V, std::list<int>& L) {
  auto iter_list = std::next(L.begin(), 5);
  std::vector<int> left_side(V.begin(), V.begin() + 5);
  L.insert(iter_list, left_side.rbegin(), left_side.rend());

  std::cout << "Список L: ";
  for (std::list<int>::const_iterator it = L.cbegin(); it != L.cend(); ++it) {
    std::cout << *it << " ";
  }
}
```

# Тестирование
<img width="315" height="43" alt="image" src="https://github.com/user-attachments/assets/625cdeaa-efea-4e87-b3ac-ed36e472c869" />
<img width="556" height="392" alt="image" src="https://github.com/user-attachments/assets/6909b305-6c8e-4986-b493-1d6821f05521" />
<img width="558" height="440" alt="image" src="https://github.com/user-attachments/assets/a2f3ead7-eb2b-4877-ac85-50238f7ab1d7" />

# Задание 3

Поменять местами первую половину списка L1 и вторую половину списка L2.

1. Запросить четные размеры для списков L1 и L2.
2. Заполнить списки.
3. Найти середины обоих списков.
4. Использовать splice для перемещения элементов:
4.1 Переместить вторую половину L2 в начало L1.
4.2 Переместить первую половину L1 в конец L2.

Реализация

```cpp
void task3(std::list<int>& L1, std::list<int>& L2) {
  auto L1_mid = std::next(L1.begin(), (L1.size() / 2));
  auto L2_mid = std::next(L2.begin(), (L2.size() / 2));
  auto L1_begin = L1.begin();

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
```

# Тестирование
<img width="536" height="115" alt="image" src="https://github.com/user-attachments/assets/d5f48fbf-e6a3-49ee-b8ee-0a1314f5b77d" />
<img width="543" height="346" alt="image" src="https://github.com/user-attachments/assets/9cad20e3-072a-4e76-be8b-a4ec4706c35b" />

# Задача 4

Записать в текстовый файл все слова из исходного файла, длина которых не превосходит K.

1. Запросить K > 0.
2. Запросить имена входного и выходного файлов.
3. Открыть файлы.
4. Создать итераторы: istream_iterator для чтения слов, ostream_iterator для записи.
5. Использовать remove_copy_if с лямбдой, проверяющей длину слова.

Реализация

```cpp
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
```

# Тестирование
<img width="257" height="342" alt="image" src="https://github.com/user-attachments/assets/e28a19b4-98f1-4c3c-98a5-c24b0ac4ff80" />
<img width="560" height="154" alt="image" src="https://github.com/user-attachments/assets/dd44d182-ff42-4c96-a867-9e7f0c7ab284" />
<img width="344" height="97" alt="image" src="https://github.com/user-attachments/assets/e988a32c-5dde-40ab-b6d9-9413fbf8ed58" />
<img width="260" height="191" alt="image" src="https://github.com/user-attachments/assets/e84ff245-3618-4cce-ad1c-91cde2e2ec13" />


# Задание 5

Удалить последний нулевой элемент дека.

1. Запросить размер дека и заполнить его.
2. Использовать find с обратными итераторами для поиска нуля: std::find(D.rbegin(), D.rend(), 0).
3. Если ноль найден, удалить его с помощью erase и base().
4. Вывести измененный дек.

Реализация:

```cpp
void task5(std::deque<int>& D) {
  auto r = std::find(D.rbegin(), D.rend(), 0);
  D.erase(std::prev(r.base()));

  std::cout << "Дек после изменения: ";
  for (std::deque<int>::const_iterator it = D.cbegin(); it != D.cend(); ++it){
    std::cout << *it << " ";
  }
}
```

# Тестирование

<img width="562" height="225" alt="image" src="https://github.com/user-attachments/assets/964e5a10-f92b-4f84-a555-63ba484bca5c" />
<img width="569" height="137" alt="image" src="https://github.com/user-attachments/assets/20b30aa7-bbc0-4878-a88a-66bb64db039b" />

# Задание 6

Добавить в начало каждого вектора 5 элементов со значениями A, а в конец — 5 элементов со значениями B.

1. Запросить числа A и B.
2. Запросить размеры векторов V1 и V2 и заполнить их.
3. Для V1 использовать fill_n с inserter и back_inserter.
4. Для V2 использовать insert в начало и конец.
5. Вывести оба вектора.


Реализация:

```cpp
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
```

# Тестирование
<img width="778" height="379" alt="image" src="https://github.com/user-attachments/assets/de4bdf37-f805-4d74-bd02-8c791b786b78" />
<img width="555" height="183" alt="image" src="https://github.com/user-attachments/assets/5a809800-b926-4c8e-9d0d-2725fff1c297" />

# Задание 7

Отсортировать все элементы вектора по возрастанию: вторая половина сортируется, затем слияние половин.

1. Запросить четный размер вектора.
2. Заполнить вектор (первая половина уже отсортирована).
3. Найти середину: auto mid = std::next(V.begin(), V.size() / 2).
4. Проверить, что первая половина отсортирована.
5. Отсортировать вторую половину: std::sort(mid, V.end()).
6. Выполнить слияние: std::inplace_merge(V.begin(), mid, V.end()).
7. Вывести результат.

```cpp
void task7(std::vector<int>& V) {
  auto mid = std::next(V.begin(), (V.size() / 2));

  if (!std::is_sorted(V.begin(), mid)) {
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
```

# Тестирование

<img width="540" height="154" alt="image" src="https://github.com/user-attachments/assets/64473e54-8ad8-45d5-8abb-fc2c43e185f4" />
<img width="572" height="277" alt="image" src="https://github.com/user-attachments/assets/8b5520f4-ac05-4d5e-94d3-bd1bf4e16638" />
<img width="572" height="274" alt="image" src="https://github.com/user-attachments/assets/bd4b4d66-ae03-430d-8bd3-4980c9d6ed02" />

# Задание 8

Получить вектор средних арифметических для всех пар соседних элементов списка.

1. Запросить размер списка (минимум 2) и заполнить его.
2. Очистить результирующий вектор V.
3. Использовать adjacent_difference с лямбдой (a + b) / 2.0.
4. Удалить первый элемент вектора (он лишний).
5. Вывести результат.

```cpp
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
```

# Тестирование

<img width="573" height="169" alt="image" src="https://github.com/user-attachments/assets/e3df8ef8-e608-4d7e-9e9d-c98b73278b4d" />
<img width="601" height="222" alt="image" src="https://github.com/user-attachments/assets/c13fe070-9ad9-4bfe-a7bd-11e6803d8166" />

# Задача 9
Найти количество векторов, которые содержат все элементы вектора V0.

1. Запросить размер V0 и заполнить его.
2. Запросить количество проверяемых векторов.
3. Для каждого вектора запросить размер (не меньше размера V0) и заполнить его.
4. Создать множество set0 из V0.
5. Для каждого вектора создать множество set_i и проверить includes(set_i, set0).
6. Подсчитать количество успешных проверок.

Реализация

```cpp
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
```

# Тестирование
<img width="590" height="528" alt="image" src="https://github.com/user-attachments/assets/b49ddb34-f6d5-4472-bf14-211ca3cf7931" />

# Задание 10 

Определить суммарную длину слов, начинающихся с одной и той же буквы.



1. Запросить количество слов.
2. Ввести слова заглавными английскими буквами.
3. Создать map<char, int> M.
4. Для каждого слова:
4.1 Пропустить пустые строки.
4.2 Взять первую букву.
4.3 Добавить длину слова в M[first].
5. Вывести буквы в алфавитном порядке и суммарную длину.

Реализация

```cpp
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
```

#Тестирование
<img width="545" height="334" alt="image" src="https://github.com/user-attachments/assets/50f134f9-11ad-4c0e-ad55-4be0881921af" />

