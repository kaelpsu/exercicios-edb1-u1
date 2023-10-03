#include <iostream>
#include <array>
#include <unordered_map>

struct Result {
    int indexA1;
    int indexA2;
    int indexB;

    Result(int a1, int a2, int b) : indexA1(a1), indexA2(a2), indexB(b) {}
};

int* binarySearch(int *first, int *last, int &target) {
    int *left = first;
    int *right = last;

    while (left <= right) {
        int *mid = left + (right-left)/2;
        
        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    return last;
}

Result findSumIndices(std::array<int, 4>& A, std::array<int, 5>& B) {
    int sum;

    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            sum = A[i] + A[j];
            int *b_element = binarySearch(B.begin(), B.end(), sum);

            if (b_element != B.end()) {
                return Result(i, j, std::distance(B.begin(), b_element));
            }
        }
    }

    return Result(-1, -1, -1);
}

int main() {
    std::array<int, 4> A {2, 4, 6, 8};
    std::array<int, 5> B {10, 12, 14, 16};

    Result result = findSumIndices(A, B);

    if (result.indexA1 != -1 && result.indexA2 != -1 && result.indexB != -1) {
        std::cout << "Indices in A: " << result.indexA1 << ", " << result.indexA2 << std::endl;
        std::cout << "Index in B: " << result.indexB << std::endl;
    } else {
        std::cout << "No such indices found." << std::endl;
    }

    return 0;
}
