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
![Uploading image.png…]()





















