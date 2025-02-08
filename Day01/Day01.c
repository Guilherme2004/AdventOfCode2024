#include <stdio.h>
#include <stdlib.h>

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

int binarySearch(int * pArr, int target, int low, int high){
    if(low > high) return -1;

    int middle = (low + high) / 2;

    if(pArr[middle] == target) return middle;
    if(pArr[middle] > target) return binarySearch(pArr, target, low, middle - 1);
    if(pArr[middle] < target) return binarySearch(pArr, target, middle + 1, high);
}

enum Directions {RIGHT = 1, LEFT = -1};
int checkAdjacents(int *pArr, int index, int direction, int end){
    if((direction == RIGHT && index == end) || (direction == LEFT && index == 0) || (pArr[index] != pArr[index + direction])) return index;
    else return checkAdjacents(pArr, index + direction, direction, end);
}

int main(){

    FILE *pInputFile = fopen("input.txt", "r");
    if(!pInputFile){
        printf("Error reading file!");
        return 1;
    }

    int *leftArr = NULL, *rightArr = NULL;
    int row = 0;
    int valueLeft = 0;
    int valueRight = 0;

    while(fscanf(pInputFile, "%d %d", &valueLeft, &valueRight) == 2){

        int *tempLeft = (int *)realloc(leftArr, (row + 1) * sizeof(int));
        int *tempRight = (int *)realloc(rightArr, (row + 1) * sizeof(int));
        if(!tempLeft || !tempRight){
            printf("Failed to allocate memory!");
            fclose(pInputFile);
            return 1;
        }
        leftArr = tempLeft;
        rightArr = tempRight;
        
        leftArr[row] = valueLeft;
        rightArr[row] = valueRight;
        row++;

    }
    fclose(pInputFile);

    quicksort(leftArr, 0, row);
    quicksort(rightArr, 0, row);

    int total = 0;
    for(int i = 0; i <= row; i++){

        int furthestRight = checkAdjacents(leftArr, i, 1, row);

        int rightPos = binarySearch(rightArr, leftArr[i], 0, row);
        if(rightPos == -1) continue;

        int leftmost = checkAdjacents(rightArr, rightPos, LEFT, row);
        int rightmost = checkAdjacents(rightArr, rightPos, RIGHT, row);

        total += (leftArr[i] * (rightmost - leftmost + 1)) * (furthestRight - i + 1);
        i = furthestRight;

    }

    printf("Total: %d", total);

    free(leftArr);
    free(rightArr);

    return 0;

}