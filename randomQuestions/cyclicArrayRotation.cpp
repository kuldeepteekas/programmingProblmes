//
//  main.cpp
//  pointers
//
//  Created by Kuldeep Teekas on 25/07/18.
//  Copyright © 2018 Kuldeep Teekas. All rights reserved.
//

//Program to cyclically rotate an array by one
//Given an array, cyclically rotate the array clockwise by one.

#include <iostream>
using namespace std;


void cyclicRotateArray (int* array, int size) {
    
    //if we go in forward direction then all elements will be filled with first element
    int temp = array[size - 1];
    for (int i = size -1; i > 0; i--) {
        array[i] = array[i -1];
    }
    array[0] = temp;
}

void printArray(int* array, int size) {
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main () {
    
    int arrayInt [] ={1, 2, 3, 4, 5, 6, 7, 8};
    int sizeArr = int (sizeof(arrayInt) / sizeof (arrayInt[0]));
    
    std::cout << "array before rotation" << endl;
    printArray(arrayInt, sizeArr);
    cyclicRotateArray(arrayInt, sizeArr);
    std::cout << "array after rotation" << endl;
    printArray(arrayInt, sizeArr);
    
    
}

