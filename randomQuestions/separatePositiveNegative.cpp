//
//  main.cpp
//  programTest
//
//  Created by Machintosh on 16/07/18.
//  Copyright © 2018 test. All rights reserved.
//
// Rearrange positive and negative numbers in O(n) time and O(1) extra space

#include <iostream>
using namespace std;

void separatePositiveNegative(int* array, int size) {
    
    int start = 0;
    int end = size - 1;
    
    while( start < end) {
        
        if (array[start] > 0 && array[end] < 0) {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
        
        if (array[start] < 0)
            start++;
        if (array[end] > 0)
            end--;
    }
}

void printArray(int* array, int size) {
    
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main () {
    
    int array [] = {10, 14, 1, 3, -7, -2, -9, -17};
    int sizeArray = (int)(sizeof(array)/ sizeof(array[0]));
    
    std::cout << "array before separting" << endl;
    printArray(array, sizeArray);
    separatePositiveNegative(array, sizeArray);
    std::cout << "array after separtaing" << endl;
    printArray(array, sizeArray);
 
}


