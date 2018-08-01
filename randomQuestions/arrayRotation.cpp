//
//  main.cpp
//  pointers
//
//  Created by Kuldeep Teekas on 25/07/18.
//  Copyright © 2018 Kuldeep Teekas. All rights reserved.
//
// Write a function rotate(ar[], d, n) that left rotates arr[] of size n by d elements.

#include <iostream>
using namespace std;

void rotateLeftOne(int* array, int size) {
    
    int temp = array[0];
    for (int i=0; i < size; i++) {
        array[i] = array[i+1];
    }
    array[size - 1] = temp;
}

void arrayLeftRotation(int* arr, int size, int numOfelem) {
    
    for (int i=0; i < numOfelem; i++)
        rotateLeftOne(arr, size);
}

void printArray(int *array, int size) {
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main() {
    
    int arrayInt[] = {1,2,3,4,5,6,7};
    int sizeArr = int (sizeof(arrayInt) / sizeof(arrayInt[0]));
    
    std::cout << "array before rotation is" << endl;
    printArray(arrayInt, sizeArr);
    arrayLeftRotation(arrayInt, sizeArr, 3);
    
    std::cout << "array after rotation is" << endl;
    printArray(arrayInt, sizeArr);
    
}

