#include <iostream>
#include <cstdlib>
#include <ctime>

void populate_array(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }
}

int main() {
    srand(time(nullptr));
    int array[50], size;

    std::cout << "Enter the size of the array (5-50): ";
    std::cin >> size;
    while (size < 5 || size > 50) {
        std::cout << "Invalid size. Enter a value between 5 and 50: ";
        std::cin >> size;
    }

    populate_array(array, size);
    int sum = 0, max = 0, min = 0;

    for (int i = 0; i < size; ++i) {
        sum += array[i];
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    std::cout << "Sum: " << sum << "\nMax: " << max << "\nMin: " << min << "\nAverage: " << (double)sum / size << std::endl;

    return 0;
}