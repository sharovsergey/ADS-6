// Copyright 2021 NNTU-CS
#include <iostream>

using namespace std;

struct Job
{
    int priority;
    string description;
    Job *next;

    Job(int p = 0, string d = "") : priority(p), description(d), next(nullptr) {}
};

class TPQueue
{
    private:
        Job *head;
        Job *tail;

    public:
        TPQueue() : head(nullptr), tail(nullptr) {}

        void push(int, string);
        void pop();
        Job front() const;
        bool empty() const;
};

void TPQueue::push(int priority, string description)
{
    Job *tmp = new Job(priority, description);

    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else if (priority <= head->priority)
    {
        tmp->next = head;
        head = tmp;
    }
    else
    {
        Job *cur = head;

        while (cur->next != nullptr && priority > cur->next->priority)
        {
            cur = cur->next;
        }

        tmp->next = cur->next;
        cur->next = tmp;

        if (tmp->next == nullptr)
        {
            tail = tmp;
        }
    }
}

void TPQueue::pop()
{
    if (head == nullptr)
    {
        return;
    }

    Job *tmp = head;
    head = head->next;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    delete tmp;
}

Job TPQueue::front() const
{
    return *head;
}

bool TPQueue::empty() const
{
    return (head == nullptr);
}

int main()
{
    TPQueue queue;

    queue.push(4, "Task 4");
    queue.push(2, "Task 2");
    queue.push(1, "Task 1");
    queue.push(5, "Task 5");
    queue.push(3, "Task 3");

    while (!queue.empty())
    {
        cout << queue.front().description << endl;
        queue.pop();
    }

    return 0;
}
