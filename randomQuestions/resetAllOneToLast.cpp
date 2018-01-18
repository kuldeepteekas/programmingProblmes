/*******************************************************************************************/

//Problem Statement : Rest all 1's to last in an Array of 1's and 0's

/*******************************************************************************************/

#include <iostream>
using namespace std;

void printArray(int *array, int arrLen) {
	
	for(int i=0; i< arrLen; i++) {
		cout << *array << endl;
		array++;
	}
}

//swapping all the zero's in the beginning of array and 1's in last
void resetOneToLast(int array[], int arrLen) {
    
	int i = 0;
	int j = 0;
    int k = 0;

	for (int i=0; i<arrLen; i++){
		if (array[i] != 1){		  
		   k = array[i];
           array[i] = array[j];
		   array[j] = k;          
		   j++;
		}
	}
}

int main() {
	
	int arr[] = {1,1,0,0,0,1,1,1,0,0,1,1,1};
	int arrSize = (int)sizeof(arr)/sizeof(arr[0]);
	cout << "array before sending all one to end" << endl;
	printArray(arr, arrSize);
	resetOneToLast(arr, arrSize);
	cout << "array after sending all one to end" << endl;
	printArray(arr, arrSize);
}



