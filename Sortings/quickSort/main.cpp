#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int Partition(vector<T> &A, int l, int r) {
    T x = A[l];
    int j = l;
    for (int i = l + 1; i <= r; ++i) {
        if (A[i] <= x) {
            j++;
            swap(A[i], A[j]);
        }
    }
    swap(A[l], A[j]);
    return j;
}

template<typename T>
void quickSort(vector<T> &A, int l, int r) {
    if (l >= r)
        return;
    int m = Partition(A, l, r);
    quickSort(A, l, m - 1);
    quickSort(A, m + 1, r);
}

int main() {
    vector<int> A{7, 6, 5, 4, 3, 2, 1, 33, 12, 4, 5, 22, 45};
    quickSort(A, 0, A.size() - 1);
    for (auto i : A)
        cout << i << " ";
    return 0;
}