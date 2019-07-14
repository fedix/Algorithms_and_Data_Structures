#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
vector<T> merge(vector<T> L, vector<T> R) {
    vector<T> res;
    int i = 0, j = 0;
    while (i < L.size() || j < R.size()) {
        if (j == R.size() || (i < L.size() && L[i] < R[j])) {
            res.push_back(L[i]);
            i++;
        } else {
            res.push_back(R[j]);
            j++;
        }
    }
    return res;
}

template<typename T>
vector<T> mergeSort(vector<T> A) {
    int n = A.size();

    if (n <= 1)
        return A;
    int middle = floor(n / 2);
    vector<T> L, R;

    for (auto i = 0; i < middle; ++i)
        L.push_back(A[i]);
    for (auto i = middle; i < n; ++i)
        R.push_back((A[i]));

    L = mergeSort(L);
    R = mergeSort(R);
    return merge(L, R);
}

int main() {
    vector<int> A{2, 7, 6, 3, 5, 4, 1};
    for (auto i : A)
        cout << i << " ";
    cout << "\n\n" << "sorted: " << endl;
    A = mergeSort(A);
    for (auto i : A)
        cout << i << " ";
    return 0;
}