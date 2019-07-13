#ifndef LIST_LIST_H
#define LIST_LIST_H

template<typename T>
class List {
public:
    List() : Size(0), head(nullptr) {};

    ~List() { clear(); };

    void push_front(T data);

    void push_back(T data);

    void pop_front();

    void pop_back();

    void insert(T data, int index);

    void removeAt(int index);

    void clear();

    int GetSize() const noexcept { return Size; }

    T &operator[](const int index) const noexcept;

private:
    class Node {
    public:
        Node *pNext;
        T data;

        explicit Node(T data = T(), Node *pNext = nullptr) : data(data), pNext(pNext) {}
    };

    Node *head;
    int Size;
};


#endif //LIST_LIST_H
