# PromobotTask

Мухаметсафин Руслан
ПНИПУ СРРС-22-1б

## Структура проекта

-   **`main.cpp`**: Основной файл программы. Создает массив фигур, выводит его начальное состояние и запускает сортировки в отдельных потоках.
-   **`src/sort.cpp`**: Реализация алгоритмов сортировки (быстрая, слиянием, пузырьковая) и вспомогательных функций.
-   **`src/shapeClasses.cpp`**: Реализация классов фигур (круг, прямоугольник, треугольник).
-   **`src/sort.hpp`**: Заголовочный файл с объявлениями функций сортировки.
-   **`src/shapeClasses.hpp`**: Заголовочный файл с объявлениями классов фигур.
-   **`CMakeLists.txt`**: Файл конфигурации CMake для сборки проекта.

## Зависимости

-   Компилятор C++ с поддержкой стандарта C++17.
-   CMake для сборки проекта.

## Инструкция по сборке и запуску

1.  **Клонирование репозитория:**
    ```bash
    git clone https://github.com/Thrvch/PromobotTask
    cd <название_директории>
    ```

2.  **Создание директории сборки и переход в нее:**
    ```bash
    mkdir build
    cd build
    ```

3.  **Генерация Makefile с помощью CMake:**
    ```bash
    cmake ..
    ```

4.  **Сборка проекта:**
    ```bash
    make
    ```

5.  **Запуск исполняемого файла:**
    ```bash
    ./PromobotTask
    ```

## Описание работы программы

1.  Программа создает вектор указателей на объекты базового класса `Shapes`, добавляя туда объекты классов `Circle`, `Rectangle` и `Triangle` с различными параметрами.
2.  Выводится начальное состояние массива фигур с указанием их типа и площади.
3.  Запускаются три потока:
    -   Первый поток выполняет быструю сортировку массива.
    -   Второй поток выполняет сортировку слиянием.
    -   Третий поток выполняет пузырьковую сортировку.
4.  Каждый поток выводит результаты сортировки в консоль с указанием типа сортировки и отсортированного массива.
5.  Программа завершается после завершения всех потоков.
