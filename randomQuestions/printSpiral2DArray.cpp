/************************************************************************************************************/
/*****                          Problem Statement:                                                      *****/
//          Print a given 2D Array in a Spiral Way, NxN two D matrix is given                               //
//                                                                                                          //
/************************************************************************************************************/

#include <stdio.h>
#include <cmath>
int ROW = 6;
int COL = 6;
using namespace std;

int main() {
    int array[][6] = {
        {1,2,3,4,5,6},
        {20,21,22,23,24,7},
        {19,32,33,34,25,8},
        {18,31,36,35,26,9},
        {17,30,29,28,27,10},
        {16,15,14,13,12,11}
    };
    
    double rowsToPrint = (ROW * 0.5);
    rowsToPrint = ceil(rowsToPrint);
    int numberOfRowPrinted = 0;
    int numberOfColPrinted = 0;
    int i=0, j = 0;
    while(numberOfRowPrinted <= rowsToPrint){
     
        for (j=numberOfColPrinted; j < COL; j++){
            printf("%d\n",array[numberOfRowPrinted][j]);
        }
        
        COL--;
        j--;
        
        numberOfRowPrinted++;
        for (i=numberOfRowPrinted; i < ROW; i++){
            printf("%d\n",array[i][COL]);
        }
        
        i--;
        ROW--;
        
        if (i == ROW && j == COL){
            for (j=COL-1; j>=numberOfColPrinted; j--){
                printf("%d\n",array[ROW][j]);
            }
            
            for(i = ROW-1; i>= numberOfRowPrinted; i--) {
                printf("%d\n",array[i][numberOfColPrinted]);
            }
        }
        numberOfColPrinted++;
    }
    return 0;
}
