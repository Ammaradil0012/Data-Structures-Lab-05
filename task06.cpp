#include <iostream>

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim == 1) {
        int total = 0;
        for (int i = 0; i < sizes[0]; i++) {
            total += arr[i][0];
        }
        return total;
    }

    int total = 0;
    for (int i = 0; i < sizes[0]; i++) {
        total += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
    }
    return total;
}

int main() {
    int r1[] = {1, 2, 3};
    int r2[] = {4, 5, 6};
    int* matrix[] = {r1, r2};
    int size[] = {2, 3};
    std::cout << recursiveArraySum(matrix, size, 2);
}
