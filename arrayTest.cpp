#include <iostream>
#include "G6Graphics.h"

using namespace std;

int main(int argc, char *argv[])
{
   int arr[5] = {5,4,9,3,1};
   int n = sizeof(arr) / sizeof(arr[0]);

   int i,j;
   G6SortVis(arr,n);
    for(i = 0; i < n - 1; i++){
        
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++){
                            
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                G6SortVis(arr,6);
            }
        }
    }
    return 0;

}