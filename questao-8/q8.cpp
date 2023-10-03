#include <iostream>
#include <array>

bool containsDuplicate(int *first, int *last) {
    int *start = first;
    int *end = last;

    std::array<bool, 5> visited;
    visited.fill(false);

    while (start < end) {
        if (visited[(*start)-1]) {
            return true; // Found a duplicate
        } else {
            visited[(*start)-1] = true; // Mark as visited
        }

        start++;
    }

    return false; // No duplicates found
}

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 3};
    
    bool result = containsDuplicate(arr.begin(), arr.end());

    if (result) {
        std::cout << "Array contains duplicates." << std::endl;
    } else {
        std::cout << "Array does not contain duplicates." << std::endl;
    }

    return 0;
}
