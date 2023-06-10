// Copyright 2022 NNTU-CS
#ifndef TPQUEUE_H
#define TPQUEUE_H

template<typename T>
class TPQueue
{
private:
    struct ITEM
    {
        T data;
        ITEM* next;
    };

    ITEM* head;
    ITEM* tail;
    int count;

public:
    TPQueue() : head(nullptr), tail(nullptr), count(0) {}
    ~TPQueue();

    void push(const T&);
    T pop();
    void print() const;
};

template<typename T>
TPQueue<T>::~TPQueue()
{
    while (head)
    {
        ITEM* temp = head->next;
        delete head;
        head = temp;
    }
}

template<typename T>
void TPQueue<T>::push(const T& item)
{
    ITEM* temp = new ITEM;
    temp->data = item;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else if (item.prior <= head->data.prior)
    {
        temp->next = head;
        head = temp;
    }
    else if (item.prior >= tail->data.prior)
    {
        tail->next = temp;
        tail = temp;
    }
    else
    {
        ITEM* current = head->next;
        ITEM* previous = head;

        while (current)
        {
            if (item.prior > current->data.prior)
            {
                previous->next = temp;
                temp->next = current;
                break;
            }

            previous = current;
            current = current->next;
        }
    }

    count++;
}

template<typename T>
T TPQueue<T>::pop()
{
    if (head)
    {
        ITEM* temp = head->next;
        T item = head->data;
        delete head;
        head = temp;
        count--;
        return item;
    }

    return T();
}

template<typename T>
void TPQueue<T>::print() const
{
    ITEM* current = head;

    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

#endif // TPQUEUE_H

