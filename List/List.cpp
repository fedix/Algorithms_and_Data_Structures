#include "List.h"

template<typename T>
void List<T>::push_front(T data) {
    head = new Node(data, head);
    Size++;
}

template<typename T>
void List<T>::push_back(T data) {
    auto new_node = new Node(data);

    if (head == nullptr)
        head = new_node;
    else {
        auto current = head;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = new_node;
    }
    Size++;
}

template<typename T>
void List<T>::pop_front() {
    auto temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::pop_back() {
    removeAt(Size - 1);

}

template<typename T>
void List<T>::insert(T data, int index) {
    if (index == 0)
        push_front(data);
    else {
        auto previous = head;
        for (auto i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
        auto new_node = new Node(data, previous->pNext);
        previous->pNext = new_node;
        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index) {
    if (index == 0)
        pop_front();
    else {
        auto previous = head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
        auto toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
T &List<T>::operator[](const int index) const noexcept {
    auto current = head;
    for (auto i = 0; i < index; ++i) {
        current = current->pNext;
    }
    return current->data;
}

template<typename T>
void List<T>::clear() {
    while (Size)
        pop_front();
}
