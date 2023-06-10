// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
template<typename T, int size>
class TPQueue {
 private:
  T* container;
  int volume;
  int first, second;
  int thisSize;

 public:
  TPQueue() :volume(size), first(0), second(0), thisSize(0) {
    container = new T[volume + 1];
  }
  void push(const T& value) {
    assert(thisSize < volume);
    if (thisSize == 0) {
      container[second++] = value;
      thisSize++;
    } else {
      int i = second - 1;
      bool flag = 0;
      while (i >= first && value.prior > container[i].prior) {
        flag = 1;
        container[i + 1] = container[i];
        container[i] = value;
        i--;
      }
      if (flag == 0) {
        container[second] = value;
      }
      second++;
      thisSize++;
    }
    if (second > volume) {
      second -= volume + 1;
    }
  }
  const T& pop() {
    assert(thisSize > 0);
    thisSize--;
    if (first > volume) {
      first -= volume + 1;
    }
    return container[first++];
  }
  char get() {
    assert(thisSize > 0);
    return container[first].ch;
  }
  bool isFull() const {
    return thisSize == volume;
  }
  bool isEmpty() const {
    return thisSize == 0;
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
