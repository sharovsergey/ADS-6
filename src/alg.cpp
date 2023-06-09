// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cassert>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
  T* container;
  int capacity;
  int first, last;
  int currentSize;

 public:
  TPQueue() :capacity(size), first(0), last(0), currentSize(0) {
    container = new T[capacity + 1];
  }

  void push(const T& value) {
    assert(currentSize < capacity);
    if (currentSize == 0) {
      container[last++] = value;
      currentSize++;
    } else {
      int i = last - 1;
      bool flag = 0;
      while (i >= first && value.prior > container[i].prior) {
        flag = 1;
        container[i + 1] = container[i];
        container[i] = value;
        i--;
      }
      if (flag == 0) {
        container[last] = value;
      }
      last++;
      currentSize++;
    }
    if (last > capacity) {
      last -= capacity + 1;
    }
  }

  const T& pop() {
    assert(currentSize > 0);
    currentSize--;
    if (first > capacity) {
      first -= capacity + 1;
    }
    return container[first++];
  }

  char get() {
    assert(currentSize > 0);
    return container[first].ch;
  }

  bool isFull() const {
    return currentSize == capacity;
  }

  bool isEmpty() const {
    return currentSize == 0;
  }

  ~TPQueue() {
    delete[] container;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
