#include <iostream>
#include <array>

int* binary_search_smallest(int *first, int *last, int target) {
    int *left = first;
    int *right = std::prev(last);
    int *result = last;

    while (left <= right) {
        int *mid = left + (right - left) / 2;

        if (*mid == target) {
            result = mid;  // Update the result when the target is found
            right = mid - 1;  // Continue searching on the left side for a smaller index
        } else if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    std::array<int, 9> sorted_array = {1, 2, 2, 2, 3, 4, 4, 4, 5};
    int target = 4;

    int *result = binary_search_smallest(sorted_array.begin(), sorted_array.end(), target);

    if (result != sorted_array.end()) {
        std::cout << "Smallest index of " << target << " is at index " << std::distance(sorted_array.begin(), result) << std::endl;
    } else {
        std::cout << target << " not found in the array." << std::endl;
    }

    return 0;
}
