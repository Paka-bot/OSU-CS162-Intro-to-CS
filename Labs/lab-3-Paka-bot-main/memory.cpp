#include <iostream>
using namespace std;

int* create_array1(int size) {
    return new int[size];
}

void create_array2(int*& array, int size) {
    array = new int[size];
}

void create_array3(int** array, int size) {
    *array = new int[size];
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* array1 = nullptr;
    int* array2 = nullptr;
    int* array3 = nullptr;

    array1 = create_array1(size);
    cout << "array1_address: " << array1 << endl;

    create_array2(array2, size);
    cout << "array2_address: " << array2 << endl;

    create_array3(&array3, size);
    cout << "array3_address: " << array3 << endl;

    delete[] array1;
    array1 = nullptr;

    delete[] array2;
    array2 = nullptr;

    delete[] array3;
    array3 = nullptr;

    return 0;
}
