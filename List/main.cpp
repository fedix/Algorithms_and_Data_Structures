#include <iostream>
#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
    List<int> q;
    cout << "testing as a queue" << endl;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);

    for (auto i = 0; i < q.GetSize(); i++)
        cout << q[i] << " ";
    q.pop_front();
    cout <<endl << "pop_front: ";
    for (auto i = 0; i < q.GetSize(); i++)
        cout << q[i] << " ";

    return 0;
}