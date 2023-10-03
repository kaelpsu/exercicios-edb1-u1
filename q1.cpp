#include <iostream>
#include <array>

int* find_local_minimum(int *first, int *last) {
    int *left = first;
    int *right = std::prev(last);

    while (left <= right) {
        int *mid = left + (right - left) / 2;  // Calculate the middle index
        std::cout <<"mid: " << *mid << "\n";

        // Check if mid is a local minimum
        if ((mid == first || *mid < *std::prev(mid)) && (mid == last || *mid < *std::next(mid))) {
            return mid;
        }

        // Determine which half to search based on the neighbors of mid
        if (mid > first && *std::prev(mid) < *mid) {
            // Search the left half
            right = mid - 1;
        } else {
            // Search the right half
            left = mid + 1;
        }
    }

    // If no local minimum is found, return last 
    return last;
}

int main() {
    std::array<int, 7> arr = {9, 6, 3, 14, 5, 7, 4};
    int *index = find_local_minimum(arr.begin(), arr.end());

    if (index != arr.end()) {
        std::cout << "Local minimum found at index " << std::distance(arr.begin(), index) << ": " << *index << std::endl;
    } else {
        std::cout << "No local minimum found in the array." << std::endl;
    }

    return 0;
}


