#include <iostream>
#include <array>
#include <algorithm>

bool findTripleSumZero(const std::array<int, 4>& A, const std::array<int, 4>& B, const std::array<int, 4>& C) {
    // Sort arrays B in increasing order and C in decreasing order
    std::array<int, 4> sortedB = B;
    std::array<int, 4> sortedC = C;
    std::sort(sortedB.begin(), sortedB.end());
    std::sort(sortedC.begin(), sortedC.end());
    std::reverse(sortedC.begin(), sortedC.end());

    for (int a : A) {
        int runnerB = 0;
        int runnerC = 0;

        while (runnerB < sortedB.size() && runnerC < sortedC.size()) {
            int sum = a + sortedB[runnerB] + sortedC[runnerC];

            if (sum == 0) {
                std::cout << a << " " << sortedB[runnerB] << " " << sortedC[runnerC] << "\n";
                return true; // Found a triple (a, b, c) with a + b + c = 0
            } else if (sum < 0) {
                runnerB++; // Sum is too small, advance in B
            } else {
                runnerC++; // Sum is too large, advance in C
            }
        }
    }

    return false; // No such triple found
}

int main() {
    std::array<int, 4> A = {0, 2, 3, 7};
    std::array<int, 4> B = {-2, 0, 4, 3};
    std::array<int, 4> C = {-3, 1, 5, 9};

    //A[3] B[0] + C[-3]

    bool result = findTripleSumZero(A, B, C);

    if (result) {
        std::cout << "There exists a triple (a, b, c) such that a + b + c = 0." << std::endl;
    } else {
        std::cout << "No such triple exists." << std::endl;
    }

    return 0;
}
