// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T* arr;
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == size;
    }
    void push(const T& item) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            int i = end;
            for (int j = end; j > begin; j--) {
                if (arr[j - 1].prior < item.prior) {
                    i = j - 1;
                    arr[j % size] = arr[j - 1];
                }
            }
            arr[i % size] = item;
            count++;
            end++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            count--;
            return arr[begin++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
