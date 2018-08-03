//
//  main.cpp
//  programTest
//
//  Created by Machintosh on 16/07/18.
//  Copyright © 2018 test. All rights reserved.
//
// Find top three largest element in an array

#include <iostream>
using namespace std;

void findThreeLargestElemInArray(int* array, int size) {
    int first,second, third;
    first = second = third = INT_MIN;
    
    for (int i=0; i < size; i++) {
        
        if (array[i] > first) {
            third = second;
            second = first;
            first = array[i];
        }else if (array[i] > second) {
            third = second;
            second = array[i];
        }else if (array[i] > third) {
            third = array[i];
        }
    }
    
    std::cout << "top three elements are " << first << " " << second << " " << third << endl;
    

}

void printArray(int* array, int size) {
    
    for (int i=0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}

int main () {
    
    int array [] = {121, 890, 76, 43,0, -1, 9};
    int sizeArray = (int)(sizeof(array)/ sizeof(array[0]));
    findThreeLargestElemInArray(array, sizeArray);
}


