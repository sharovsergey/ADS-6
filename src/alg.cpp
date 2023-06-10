// Copyright 2022 NNTU-CS
#include <iostream>
#include "include/tpqueue.h" // Подключение файла с реализацией TPQueue

struct SYM {
    char ch;
    int prior;
};

// Переопределение оператора << для вывода объектов типа SYM
std::ostream& operator<<(std::ostream& os, const SYM& item) {
    os << item.ch << '(' << item.prior << ')';
    return os;
}

int main() {
    setlocale(LC_ALL, "Russian");
    TPQueue<SYM> queue;

    // Добавление элементов в очередь
    SYM item1 = { 'A', 5 };
    SYM item2 = { 'B', 3 };
    SYM item3 = { 'C', 8 };
    SYM item4 = { 'D', 2 };

    queue.push(item1);
    queue.push(item2);
    queue.push(item3);
    queue.push(item4);

    // Вывод содержимого очереди
    std::cout << "Очередь: ";
    queue.print(); // Ожидаемый результат: D B A C
    std::cout << "Ожидаемый результат: D B A C" << std::endl << std::endl;

    // Извлечение элемента с наивысшим приоритетом
    SYM highestPriorityItem = queue.pop();
    std::cout << "Символ с самым высоким приоритетом: " << highestPriorityItem.ch << std::endl; // Ожидаемый результат: D
    std::cout << "Ожидаемый результат: D" << std::endl << std::endl;

    // Вывод содержимого очереди после извлечения элемента
    std::cout << "Очередь после команды pop: ";
    queue.print(); // Ожидаемый результат: B A C
    std::cout << "Ожидаемый результат: B A C" << std::endl << std::endl;

    SYM item5 = { 'Q', 1 };
    queue.push(item5);

    std::cout << "Очередь после команды push: ";
    queue.print(); // Ожидаемый результат: Q B A C
    std::cout << "Ожидаемый результат: Q B A C" << std::endl << std::endl;

    return 0;
}
