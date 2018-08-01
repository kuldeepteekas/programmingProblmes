//
//  main.cpp
//  pointers
//
//  Created by Kuldeep Teekas on 25/07/18.
//  Copyright © 2018 Kuldeep Teekas. All rights reserved.
//

//Write a program to reverse an array or string

#include <iostream>
using namespace std;


void reverseArray(int* array, int size) {
    
    int i=0;
    int j = size -1;
    
    while (i <= j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

void reverseRecursive(int* array, int start, int end) {
    
    if (start >= end)
        return;
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    
    reverseRecursive(array, start + 1, end - 1);
    
}

void printArray(int* array, int size) {
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main () {
    
    int array [] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    int sizeArr = int (sizeof(array) / sizeof (array[0]));
    
    std::cout << "array before reverse" << endl;
    printArray(array, sizeArr);
    reverseRecursive(array, 0, sizeArr -1);
    std::cout << "array after reverse" << endl;
    printArray(array, sizeArr);
    
    
}

