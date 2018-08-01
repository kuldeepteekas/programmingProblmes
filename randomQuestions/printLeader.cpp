//
//  main.cpp
//  pointers
//
//  Created by Kuldeep Teekas on 25/07/18.
//  Copyright © 2018 Kuldeep Teekas. All rights reserved.
//

/*Leaders in an array
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.

Let the input array be arr[] and size of the array be size.
*/

#include <iostream>
using namespace std;


void printLeader(int* array, int size) {
    
    int max = array[size -1];
    std::cout << max << endl;
    
    for (int i= size -1; i >=0; i--) {
        if (max < array[i]) {
            std::cout << array[i] << endl;
            max = array[i];
        }
    }
}

int main () {
    
    int array [] = {21, 4, 8, 14, 3, 11, 5, 12, 6};
    int sizeArr = int (sizeof(array) / sizeof (array[0]));
    printLeader(array, sizeArr);
}

