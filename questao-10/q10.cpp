#include <iostream>
#include <array>

int findJump(int *first, int *last) {
    int *left = first;
    int *right = std::prev(last);

    while (left < right) {
        int *mid = left + (right - left) / 2;
        int expected_value = std::distance(first, mid) + 1;  // The expected value at index mid

        if (*mid == expected_value) {
            // If the value at mid is as expected, search in the right half
            left = mid + 1;
        } else {
            // If the value at mid is not as expected, search in the left half
            right = mid;

        }
    }

    return *std::prev(left) + 1;  // Add 1 to get the value of k
}

int main() {
    std::array<int, 9> arr = {1, 2, 3, 4, 5, 6, 9, 11, 13};
    
    int k = findJump(arr.begin(), arr.end());

    std::cout << "The value of k is: " << k << std::endl;

    return 0;
}