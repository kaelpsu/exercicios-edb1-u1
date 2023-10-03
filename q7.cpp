#include <iostream>
#include <array>

int *findIndexEqualToValue(int *first, int *last) {
    int *N = last;

    // Check the first element
    if (*first == 0) {
        return first;
    }

    // Check the last element
    if (*std::prev(N) == std::distance(first, std::prev(N))) {
        return std::prev(N);
    }

    // Binary search for the rest of the array
    int *left = first;
    int *right = std::prev(N);

    while (left <= right) {
        int *mid = left + (right - left) / 2;

        if (*mid == std::distance(first, mid)) {
            return mid;
        } else if (*mid < std::distance(first, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return last; // If no such index exists
}

int main() {
    std::array<int, 8> arr = {-10, -5, 2, 9, 14, 21, 27, 30};
    int *result = findIndexEqualToValue(arr.begin(), arr.end());

    if (result != arr.end()) {
        std::cout << "Index " << std::distance(arr.begin(), result) << " has the value " << *result << std::endl;
    } else {
        std::cout << "No index with a[i] = i found in arr." << std::endl;
    }

    return 0;
}
