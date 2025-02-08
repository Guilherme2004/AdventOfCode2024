#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkArray(int *pArr, int idxToSkip){
    int lastDiff = 0;
    for(int j = 2; j <= pArr[0]; j++){

        if(j == idxToSkip || (idxToSkip == 1 && j == 2)) continue;

        int idxLeft = (j == idxToSkip + 1) ? j-2 : j-1;

        int diff = pArr[j] - pArr[idxLeft];

        if(diff == 0 || diff > 3 || diff < -3 || (diff > 0 && lastDiff < 0) || (diff < 0 && lastDiff > 0)){
            return 0;
        }

        lastDiff = diff;

    }
    return 1;
}

int main(){

    int **pArrRow = NULL;
    
    FILE *pInputFile = fopen("input.txt","r");
    if(!pInputFile){
        printf("Error reading file!");
        return 1;
    }

    char *fBuffer = malloc(255);
    int row = 0;

    while(fgets(fBuffer, 255, pInputFile)){

        int **temp = (int **)realloc(pArrRow, (row + 1) * sizeof(int *));
        if(!temp){
            printf("Failed to allocate memory!");
            fclose(pInputFile);
            return 1;
        }
        pArrRow = temp;

        int column = 1;
        int i = 0;
        while(fBuffer[i]){
            if(fBuffer[i] == ' '){
                column++;
            }
            i++;
        }

        pArrRow[row] = (int *)malloc((column + 1) * sizeof(int));
        pArrRow[row][0] = column;
        char *pColumns = strtok(fBuffer, " ");
        column = 1;
        while(pColumns != NULL){
            sscanf(pColumns, "%d", &pArrRow[row][column]);
            pColumns = strtok(NULL, " ");
            column++;
        }
        row++;
    }
    fclose(pInputFile);
    free(fBuffer);

    int safeCount = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j <= pArrRow[i][0]; j++){
            if(checkArray(pArrRow[i], j)){
                safeCount++;
                break;
            };
        }
        free(pArrRow[i]);
    }

    printf("Safe: %d",safeCount);

    free(pArrRow);

    return 0;
}