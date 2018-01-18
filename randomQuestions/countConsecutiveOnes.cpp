/*******************************************************************************************/

    //Problem Statement : Count the number of Maximum consecutive One's in an Array
    //of 1's and 0's

/*******************************************************************************************/

#include <iostream>
using namespace std;

int numberOfConsecutiveOnes(int* , int);

int main(){
	int arrOne[] = {1,0,0,0,1,1,1,1,1,0,0};

	int len = sizeof(arrOne)/sizeof(arrOne[0]);	
	int count = numberOfConsecutiveOnes(arrOne, len);
	cout << "number of consecutive one are : " << count << endl;	
	return 0;	
}

int numberOfConsecutiveOnes(int *arr, int size) {

	int count_max = 0;
	int max_one = 0;
	
	for (int i=0; i< size; i++) {
		if (*arr == 1){
			count_max++;
		}else{
			if (count_max > max_one){
				max_one = count_max;
			}
			count_max = 0;
		}
		arr++;
	}
	return max_one;
}

