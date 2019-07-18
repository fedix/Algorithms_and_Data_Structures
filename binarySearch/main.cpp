#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>

int binarySearch(const std::vector<int> &numbers, int number) {
    int l = 0, r = numbers.size() - 1;
    while (l <= r) {
        int m = floor((l + r) / 2);
        if (numbers[m] == number)
            return m + 1;
        else if (numbers[m] > number)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main() {

    std::vector<int> numbers{1, 5, 8, 12, 13};

    assert(std::is_sorted(numbers.begin(), numbers.end()));

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << binarySearch(numbers, number) << " ";
    }
    std::cout << std::endl;
}