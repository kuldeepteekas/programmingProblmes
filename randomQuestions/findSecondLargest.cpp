//
//  main.cpp
//  programTest
//
//  Created by Machintosh on 16/07/18.
//  Copyright © 2018 test. All rights reserved.
//
// Find Second largest element in an array

#include <iostream>
using namespace std;

void findSecondLargestInArray(int* array, int size) {
    
    int first = INT_MIN;
    int second = INT_MIN;
    
    for (int i=0; i < size; i++) {
        if (array[i] > first) {
            second = first;
            first = array[i];
        }else if (array[i] > second && array[i] != first) {
            second = array[i];
        }
    }
    
    if (second == INT_MIN) {
        std::cout << "there is no second largest" << endl;
    }else {
        std::cout << "second largest is " << second << endl;
    }
}

void printArray(int* array, int size) {
    
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main () {
    
    int array [] = {21,18,-3,8,98,6,17,80};
    int sizeArray = (int)(sizeof(array)/ sizeof(array[0]));
    findSecondLargestInArray(array, sizeArray);
}


