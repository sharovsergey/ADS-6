// Copyright 2021 NNTU-CS
#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class TPQueue
{
  // Сюда поместите определения структур и функций
private:
    T* arr;
    int size;
    int begin,
    end;
    int count;
public:
    TPQueue(int = 100);
    ~TPQueue();
    void push(const T &);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};

// Определение методов шаблона класса:

template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), 
    end(0), 
    count(0)
{
    arr = new T[size + 1];
}

template<typename T>
TPQueue<T>::~TPQueue()
{
    delete[] arr;
}

template<typename T>
void TPQueue<T>::push(const T& item)
{
    assert(count < size);
    int cur = end;
    while (cur != begin && item.prior > arr[(cur - 1 + size) % size].prior)
    {
        arr[cur] = arr[(cur - 1 + size) % size];
        cur = (cur - 1 + size) % size;
    }
    arr[cur] = item;
    end = (end + 1) % size;
    count++;
}

template<typename T>
T TPQueue<T>::pop()
{
    assert(count > 0);
    T item = arr[begin];
    begin = (begin + 1) % size;
    count--;
    return item;
}

template<typename T>
T TPQueue<T>::get() const
{
    assert(count > 0);
    return arr[begin];
}

template<typename T>
bool TPQueue<T>::isEmpty() const
{
    return (count == 0);
}

template<typename T>
bool TPQueue<T>::isFull() const
{
    return (count == size);
}

struct SYM
{
	char ch;
  int  prior;
};
};
