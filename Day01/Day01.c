#include <stdio.h>

#define SIZE 6
/* Input for testing
3   4
4   3
2   5
1   3
3   9
3   3
*/

//Quicksort Algorithm
int partition(int* pArr, int low, int high){
    int aux = 0;
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(pArr[j] < pArr[high] || j == high){
            i++;
            aux = pArr[i];
            pArr[i] = pArr[j];
            pArr[j] = aux;
        }
    }
    return i;
}
int* quicksort(int* pArr, int low, int high){
    if(low < high){
        int pivot = partition(pArr, low, high);
        quicksort(pArr, low, pivot - 1);
        quicksort(pArr, pivot + 1, high);
    }
    return pArr;
}

int main(){

    int leftArr[SIZE], rightArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d %d", &leftArr[i], &rightArr[i]);
    }

    quicksort(leftArr, 0, SIZE - 1);
    quicksort(rightArr, 0, SIZE - 1);

    int sum = 0;
    for(int i = 0; i < SIZE; i++){
        sum += (leftArr[i] > rightArr[i]) ? (leftArr[i] - rightArr[i]) : (rightArr[i] - leftArr[i]);
    }

    printf("%d", sum);
    return 0;

}
