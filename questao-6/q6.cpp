#include <iostream>
#include <array>

void find_floor_ceiling(int *first, int *last, int x, int& floor, int& ceiling) {
    int *left = first;
    int *right = std::prev(last);

    // default values
    floor = -1;
    ceiling = -1;

    while (left <= right) {
        int *mid = left + (right - left) / 2;

        if (*mid == x) {
            // If the current element is equal to x, it is both the floor and the ceiling
            floor = *mid;
            ceiling = *mid;
            return;
        } else if (*mid < x) {
            // Update floor and search the right half
            floor = *mid;
            left = mid + 1;
        } else {
            // Update ceiling and search the left half
            ceiling = *mid;
            right = mid - 1;
        }
    }
}

int main() {
    std::array<int, 6> sorted_array = {2, 4, 6, 8, 10, 12};
    int x = 5;
    int floor, ceiling;

    find_floor_ceiling(sorted_array.begin(), sorted_array.end(), x, floor, ceiling);

    if (floor != -1) {
        std::cout << "Floor of " << x << " is " << floor << std::endl;
    } else {
        std::cout << "Floor of " << x << " not found." << std::endl;
    }

    if (ceiling != -1) {
        std::cout << "Ceiling of " << x << " is " << ceiling << std::endl;
    } else {
        std::cout << "Ceiling of " << x << " not found." << std::endl;
    }

    return 0;
}
